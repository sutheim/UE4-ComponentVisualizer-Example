#include "ConnectorVisualizer.h"
#include "Connector.h"

// Contains most of the stuff you need for visualization
#include "SceneManagement.h"

void FConnectorVisualizer::DrawVisualization(const UActorComponent* Component, const FSceneView* View, FPrimitiveDrawInterface* PDI)
{
	// Cast the incoming component to our UConnector class
	const UConnector* connector = Cast<const UConnector>(Component);

	// Draw a cylinder around the object because why not
	DrawWireCylinder(PDI,
		connector->GetOwner()->GetActorLocation(),
		FVector(1, 0, 0),		// The cylinder matrix, here it's just static
		FVector(0, 1, 0),
		FVector(0, 0, 1),
		FLinearColor(0, 0, 1),	// Blue color
		75, 75, 12,				// Various measurements for the cylinder
		SDPG_Foreground,		// Will render on top of everything
		2.f						// Line width
	);

	// Loop over all the actors in the array
	for (int i = 0; i < connector->targets.Num(); i++)
	{
		// Grab it from the array and verify that it's valid, as indicies can be empty
		AActor* target = connector->targets[i];
		if (target)
		{
			// Draw a line between the actor of the component and the target from the array
			PDI->DrawLine(
				connector->GetOwner()->GetActorLocation(),
				target->GetActorLocation(),
				FLinearColor(1.f, 0.f, 0.f),	// Red color
				SDPG_World,						// Will not render over other things
				2.0f);							// Line width
		}
	}
}
