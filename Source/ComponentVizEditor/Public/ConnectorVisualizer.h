#pragma once
#include "ComponentVisualizer.h"

class COMPONENTVIZEDITOR_API FConnectorVisualizer : public FComponentVisualizer
{
private:
	// This is the only method we need to override from FComponentVisualizer for this example
	virtual void DrawVisualization(const UActorComponent* Component, const FSceneView* View, FPrimitiveDrawInterface* PDI) override;
};
