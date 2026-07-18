using System.Net.Http.Headers;
using System.Text.Json;
using System.Text.Json.Serialization;

namespace codegen;

/// <summary>Downloads the UnitsNet unit-definition files from GitHub.</summary>
public sealed class DefinitionsDownloader
{
    private const string RepositoryContentsUrl =
        "https://api.github.com/repos/angularsen/UnitsNet/contents/Common/UnitDefinitions?ref=master";

    private readonly HttpClient _httpClient;

    public DefinitionsDownloader(HttpClient? httpClient = null)
    {
        _httpClient = httpClient ?? CreateHttpClient();
    }

    /// <summary>
    /// Downloads all files below <c>Common/UnitDefinitions</c> and returns the local directory.
    /// </summary>
    public async Task<string> DownloadAsync(
        string? destinationDirectory = null,
        CancellationToken cancellationToken = default)
    {
        var destination = destinationDirectory
            ?? Path.Combine(AppContext.BaseDirectory, "UnitDefinitions");

        Directory.CreateDirectory(destination);
        await DownloadDirectoryAsync(RepositoryContentsUrl, destination, cancellationToken);
        return destination;
    }

    private async Task DownloadDirectoryAsync(
        string contentsUrl,
        string destinationDirectory,
        CancellationToken cancellationToken)
    {
        using var response = await _httpClient.GetAsync(contentsUrl, cancellationToken);
        response.EnsureSuccessStatusCode();

        await using var stream = await response.Content.ReadAsStreamAsync(cancellationToken);
        var entries = await JsonSerializer.DeserializeAsync<List<GitHubContentEntry>>(
            stream, cancellationToken: cancellationToken)
            ?? throw new InvalidOperationException("GitHub returned an empty directory listing.");

        foreach (var entry in entries)
        {
            var localPath = Path.Combine(destinationDirectory, entry.Name);

            if (entry.Type == "dir")
            {
                Directory.CreateDirectory(localPath);
                await DownloadDirectoryAsync(entry.Url, localPath, cancellationToken);
            }
            else if (entry.Type == "file" && entry.DownloadUrl is not null)
            {
                using var fileResponse = await _httpClient.GetAsync(entry.DownloadUrl, cancellationToken);
                fileResponse.EnsureSuccessStatusCode();
                await using var source = await fileResponse.Content.ReadAsStreamAsync(cancellationToken);
                await using var target = File.Create(localPath);
                await source.CopyToAsync(target, cancellationToken);
            }
        }
    }

    private static HttpClient CreateHttpClient()
    {
        var client = new HttpClient();
        client.DefaultRequestHeaders.UserAgent.Add(new ProductInfoHeaderValue("unitsnet-cpp-codegen", "1.0"));
        client.DefaultRequestHeaders.Accept.Add(new MediaTypeWithQualityHeaderValue("application/vnd.github+json"));
        return client;
    }

    private sealed class GitHubContentEntry
    {
        [JsonPropertyName("name")]
        public required string Name { get; init; }

        [JsonPropertyName("type")]
        public required string Type { get; init; }

        [JsonPropertyName("url")]
        public required string Url { get; init; }

        [JsonPropertyName("download_url")]
        public string? DownloadUrl { get; init; }
    }
}
