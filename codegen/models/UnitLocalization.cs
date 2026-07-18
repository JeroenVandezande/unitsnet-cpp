namespace codegen.Models;

/// <summary>Localized abbreviations for a unit.</summary>
public sealed class UnitLocalization
{
    public required string Culture { get; init; }
    public List<string> Abbreviations { get; init; } = [];
}
