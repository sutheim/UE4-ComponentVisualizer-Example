// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Connector.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class COMPONENTVIZ_API UConnector : public UActorComponent
{
	GENERATED_BODY()

public:	
	UConnector();

	// Array to hold the targets
	UPROPERTY(BlueprintReadWrite, EditInstanceOnly)
	TArray<AActor*> targets;

protected:
	virtual void BeginPlay() override;

public:	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
};
