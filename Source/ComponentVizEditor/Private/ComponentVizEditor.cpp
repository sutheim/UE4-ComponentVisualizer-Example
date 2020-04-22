#include "ComponentVizEditor.h"
#include "UnrealEd.h"
#include "ConnectorVisualizer.h"
#include "Connector.h"

// Actually registers the module
IMPLEMENT_GAME_MODULE(FComponentVizEditorModule, ComponentVizEditor);

void FComponentVizEditorModule::StartupModule()
{
	if (GUnrealEd)
	{
		// Make a new instance of the visualizer
		TSharedPtr<FComponentVisualizer> visualizer = MakeShareable(new FConnectorVisualizer());

		// Register it to our specific component class
		GUnrealEd->RegisterComponentVisualizer(UConnector::StaticClass()->GetFName(), visualizer);
		visualizer->OnRegister();
	}
}

void FComponentVizEditorModule::ShutdownModule()
{
	if (GUnrealEd)
	{
		// Unregister when the module shuts down
		GUnrealEd->UnregisterComponentVisualizer(UConnector::StaticClass()->GetFName());
	}
}

