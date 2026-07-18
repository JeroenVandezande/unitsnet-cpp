namespace codegen.Models;

/// <summary>Describes one physical quantity and its available units.</summary>
public sealed class UnitDefinition
{
    public required string Name { get; init; }
    public required string BaseUnit { get; init; }
    public string? XmlDocSummary { get; init; }
    public List<UnitDefinitionUnit> Units { get; init; } = [];
}
