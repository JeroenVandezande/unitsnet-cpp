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
        var fromBaseExpression = ToCppExpression(unit.FromBaseToUnitFunc, "base_value_");

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
            FromBaseExpression = fromBaseExpression,
            XmlDocSummary = unit.XmlDocSummary
        };
    }

    private static string ApplyPrefix(string? prefix, string unitName) =>
        prefix is null ? unitName : $"{prefix}{char.ToLowerInvariant(unitName[0])}{unitName[1..]}";

    private static string ToCppExpression(string expression, string valueExpression) =>
        Regex.Replace(
            expression.Replace("{x}", valueExpression).Replace("Math.PI", "std::numbers::pi_v<un_scalar_t>"),
            @"(?<=\d)d\b",
            string.Empty);

    private static readonly IReadOnlyDictionary<string, string> PrefixFactors =
        new Dictionary<string, string>
        {
            ["Femto"] = "static_cast<un_scalar_t>(1e-15)",
            ["Pico"] = "static_cast<un_scalar_t>(1e-12)",
            ["Nano"] = "static_cast<un_scalar_t>(1e-9)",
            ["Micro"] = "static_cast<un_scalar_t>(1e-6)",
            ["Milli"] = "static_cast<un_scalar_t>(1e-3)",
            ["Centi"] = "static_cast<un_scalar_t>(1e-2)",
            ["Deci"] = "static_cast<un_scalar_t>(1e-1)",
            ["Deca"] = "static_cast<un_scalar_t>(1e1)",
            ["Hecto"] = "static_cast<un_scalar_t>(1e2)",
            ["Kilo"] = "static_cast<un_scalar_t>(1e3)",
            ["Mega"] = "static_cast<un_scalar_t>(1e6)",
            ["Giga"] = "static_cast<un_scalar_t>(1e9)",
            ["Tera"] = "static_cast<un_scalar_t>(1e12)",
            ["Peta"] = "static_cast<un_scalar_t>(1e15)",
            ["Exa"] = "static_cast<un_scalar_t>(1e18)",
            ["Kibi"] = "static_cast<un_scalar_t>(1024.0)",
            ["Mebi"] = "static_cast<un_scalar_t>(1048576.0)",
            ["Gibi"] = "static_cast<un_scalar_t>(1073741824.0)",
            ["Tebi"] = "static_cast<un_scalar_t>(1099511627776.0)",
            ["Pebi"] = "static_cast<un_scalar_t>(1125899906842624.0)",
            ["Exbi"] = "static_cast<un_scalar_t>(1152921504606846976.0)"
        };
}
