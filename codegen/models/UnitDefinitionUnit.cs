using System.Text.RegularExpressions;

namespace codegen.Models;

/// <summary>Describes a single unit within a <see cref="UnitDefinition"/>.</summary>
public sealed class UnitDefinitionUnit
{
    private string _fromUnitToBaseFunc = String.Empty;
    private string _fromBaseToUnitFunc = String.Empty;

    public required string SingularName { get; init; }
    public required string PluralName { get; init; }
    public string? XmlDocSummary { get; init; }

    public required string FromUnitToBaseFunc {
        get
        {
            string result1 = Regex.Replace(
                _fromUnitToBaseFunc,
                @"\b(\d+)d\b",
                "$1.0"
            );
            string result2 = Regex.Replace(
                result1,
                @"[-+]?(?:\d+(?:\.\d*)?|\.\d+)(?:[eE][-+]?\d+)?",
                match => $"static_cast<un_scalar_t>({match.Value})"
            );
            return result2;
        }
        set
        {
            _fromUnitToBaseFunc = value;
        }
    }
    public required string FromBaseToUnitFunc {
        get
        {
            string result1 = Regex.Replace(
                _fromBaseToUnitFunc,
                @"\b(\d+)d\b",
                "$1.0"
            );
            string result2 = Regex.Replace(
                result1,
                @"[-+]?(?:\d+(?:\.\d*)?|\.\d+)(?:[eE][-+]?\d+)?",
                match => $"static_cast<un_scalar_t>({match.Value})"
            );
            return result2;
        }
        set
        {
            _fromBaseToUnitFunc = value;
        } }
    public List<string> Prefixes { get; init; } = [];
    public List<UnitLocalization> Localization { get; init; } = [];
}
