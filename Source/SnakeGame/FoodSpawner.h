// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"
#include "FoodSpawner.generated.h"

UCLASS()
class SNAKEGAME_API AFoodSpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFoodSpawner();

	UPROPERTY(VisibleAnyWhere, BlueprintReadOnly)
	UBoxComponent* BoxComponent;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<AActor> FoodClass;

	UPROPERTY(EditDefaultsOnly)
	int FoodCount;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
