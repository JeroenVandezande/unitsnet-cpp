namespace codegen.Models;

/// <summary>Describes a single unit within a <see cref="UnitDefinition"/>.</summary>
public sealed class UnitDefinitionUnit
{
    public required string SingularName { get; init; }
    public required string PluralName { get; init; }
    public required string FromUnitToBaseFunc { get; init; }
    public required string FromBaseToUnitFunc { get; init; }
    public List<string> Prefixes { get; init; } = [];
    public List<UnitLocalization> Localization { get; init; } = [];
}
