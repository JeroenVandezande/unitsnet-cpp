using System.Text.Json;
using System.Text.Json.Serialization;
using UnitsNet;
using UnitsNet.Units;

if (args.Length != 2)
{
    Console.Error.WriteLine("Usage: UnitsNet.CSharpInterop <input.json> <output.json>");
    return 2;
}

LengthDto? dto = JsonSerializer.Deserialize<LengthDto>(File.ReadAllText(args[0]));
if (dto is null)
{
    Console.Error.WriteLine("Unable to deserialize the C++ Length DTO.");
    return 1;
}

if (!Enum.TryParse(dto.Unit, out LengthUnit unit))
{
    Console.Error.WriteLine($"Unknown Length unit: {dto.Unit}");
    return 1;
}

Length length = Length.From(dto.Value, unit);
Length tripled = length * 3;
LengthDto result = new(tripled.As(unit), unit.ToString());

var options = new JsonSerializerOptions { WriteIndented = true };
File.WriteAllText(args[1], JsonSerializer.Serialize(result, options) + Environment.NewLine);
return 0;

internal sealed record LengthDto(
    [property: JsonPropertyName("value")] double Value,
    [property: JsonPropertyName("unit")] string Unit);
