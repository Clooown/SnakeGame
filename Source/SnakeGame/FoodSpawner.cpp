// Fill out your copyright notice in the Description page of Project Settings.


#include "FoodSpawner.h"
#include <Kismet/KismetMathLibrary.h>

// Sets default values
AFoodSpawner::AFoodSpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	BoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("MeshComponent"));
	BoxComponent->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	BoxComponent->SetCollisionResponseToAllChannels(ECR_Ignore);
}

// Called when the game starts or when spawned
void AFoodSpawner::BeginPlay()
{
	Super::BeginPlay();

	FActorSpawnParameters SpawnInfo;
	if(FoodClass)
		for (int i = 0; i <= FoodCount; i++) {
			FVector SpawnLocation = UKismetMathLibrary::RandomPointInBoundingBox(GetActorLocation(), BoxComponent->GetScaledBoxExtent());
			GetWorld()->SpawnActor<AActor>(FoodClass, SpawnLocation, FRotator::ZeroRotator, SpawnInfo);
		}
	
}

// Called every frame
void AFoodSpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

