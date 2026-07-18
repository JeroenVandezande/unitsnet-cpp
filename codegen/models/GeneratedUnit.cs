namespace codegen.Models;

/// <summary>A unit expanded for C++ code generation, including an optional SI or binary prefix.</summary>
public sealed class GeneratedUnit
{
    public required string SingularName { get; init; }
    public required string EnumName { get; init; }
    public required string MethodName { get; init; }
    public required string ToBaseExpression { get; init; }
    public required string FromBaseExpression { get; init; }
}
