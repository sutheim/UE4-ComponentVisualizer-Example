using UnrealBuildTool;

public class ComponentVizEditor : ModuleRules
{
    public ComponentVizEditor(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
		// ComponentViz needed for the objects we're visualizing
        PublicDependencyModuleNames.AddRange(new string[] {  "Core", "Engine", "CoreUObject", "ComponentViz" });
		// Needed for our editor logic
        PrivateDependencyModuleNames.AddRange(new string[] { "UnrealEd" });
    }
}