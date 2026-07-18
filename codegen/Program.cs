namespace codegen;

using System.Text.Json;
using System.Text.RegularExpressions;
using codegen.Models;
using Scriban;
using Scriban.Runtime;

class Program
{
    static async Task Main(string[] args)
    {
        var downloader = new DefinitionsDownloader();
        var definitionsFolder = await downloader.DownloadAsync();

        Console.WriteLine($"Downloaded definitions to: {definitionsFolder}");
        
        var templateText = await File.ReadAllTextAsync("Templates/unit.hpp.scriban");
        var serializerOptions = new JsonSerializerOptions
        {
            AllowTrailingCommas = true
        };

        foreach (var file in Directory.GetFiles(definitionsFolder))
        {
            if (Path.GetExtension(file) == ".json")
            {
                var json = await File.ReadAllTextAsync(file);

                var definition = JsonSerializer.Deserialize<UnitDefinition>(json, serializerOptions)
                                 ?? throw new InvalidOperationException(
                                     "The unit definition JSON is empty or invalid.");

                var template = Template.Parse(templateText);

                if (template.HasErrors)
                {
                    throw new InvalidOperationException(
                        string.Join(Environment.NewLine, template.Messages));
                }

                var model = new ScriptObject();
                var units = ExpandUnits(definition);
                model.Add("name", definition.Name);
                model.Add("base_unit", GetBaseUnitEnumName(definition, units));
                model.Add("xml_doc_summary", definition.XmlDocSummary);
                model.Add("units", units);

                var context = new TemplateContext();
                context.PushGlobal(model);

                var generatedCode = await template.RenderAsync(context);

                var outputPath = Path.Combine(
                    "../../../src/generated",
                    $"{definition.Name}.hpp");

                Directory.CreateDirectory("Generated");
                await File.WriteAllTextAsync(outputPath, generatedCode);
            }
        }
    }
    
    static string ToSnakeCase(string name)
    {
        return string.Concat(
            name.Select((character, index) =>
                char.IsUpper(character) && index > 0
                    ? $"_{char.ToLowerInvariant(character)}"
                    : char.ToLowerInvariant(character).ToString()));
    }

    private static string GetBaseUnitEnumName(
        UnitDefinition definition,
        IEnumerable<GeneratedUnit> units) =>
        units.Single(unit => unit.SingularName == definition.BaseUnit).EnumName;

    private static List<GeneratedUnit> ExpandUnits(UnitDefinition definition)
    {
        var generatedUnits = new List<GeneratedUnit>();

        foreach (var unit in definition.Units)
        {
            generatedUnits.Add(CreateGeneratedUnit(unit, prefix: null));
            generatedUnits.AddRange(unit.Prefixes.Select(prefix => CreateGeneratedUnit(unit, prefix)));
        }

        return generatedUnits;
    }

    private static GeneratedUnit CreateGeneratedUnit(UnitDefinitionUnit unit, string? prefix)
    {
        var factor = prefix is null ? "1.0" : PrefixFactors[prefix];
        var valueExpression = prefix is null ? "value" : $"(value * {factor})";
        var toBaseExpression = ToCppExpression(unit.FromUnitToBaseFunc, valueExpression);
        var fromBaseExpression = ToCppExpression(unit.FromBaseToUnitFunc, "value_");

        if (prefix is not null)
        {
            fromBaseExpression = $"({fromBaseExpression}) / {factor}";
        }

        var singularName = ApplyPrefix(prefix, unit.SingularName);
        var pluralName = ApplyPrefix(prefix, unit.PluralName);
        return new GeneratedUnit
        {
            SingularName = singularName,
            EnumName = pluralName,
            MethodName = ToSnakeCase(pluralName),
            ToBaseExpression = toBaseExpression,
            FromBaseExpression = fromBaseExpression
        };
    }

    private static string ApplyPrefix(string? prefix, string unitName) =>
        prefix is null ? unitName : $"{prefix}{char.ToLowerInvariant(unitName[0])}{unitName[1..]}";

    private static string ToCppExpression(string expression, string valueExpression) =>
        Regex.Replace(
            expression.Replace("{x}", valueExpression).Replace("Math.PI", "std::numbers::pi"),
            @"(?<=\d)d\b",
            string.Empty);

    private static readonly IReadOnlyDictionary<string, string> PrefixFactors =
        new Dictionary<string, string>
        {
            ["Femto"] = "1e-15",
            ["Pico"] = "1e-12",
            ["Nano"] = "1e-9",
            ["Micro"] = "1e-6",
            ["Milli"] = "1e-3",
            ["Centi"] = "1e-2",
            ["Deci"] = "1e-1",
            ["Deca"] = "1e1",
            ["Hecto"] = "1e2",
            ["Kilo"] = "1e3",
            ["Mega"] = "1e6",
            ["Giga"] = "1e9",
            ["Tera"] = "1e12",
            ["Peta"] = "1e15",
            ["Exa"] = "1e18",
            ["Kibi"] = "1024.0",
            ["Mebi"] = "1048576.0",
            ["Gibi"] = "1073741824.0",
            ["Tebi"] = "1099511627776.0",
            ["Pebi"] = "1125899906842624.0",
            ["Exbi"] = "1152921504606846976.0"
        };
}
