// Fill out your copyright notice in the Description page of Project Settings.

#include "EnemyManager.h"

// Sets default values
AEnemyManager::AEnemyManager()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AEnemyManager::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void AEnemyManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (secondsCount >= 10)
	{
		//UE_LOG(LogTemp, Warning, TEXT("%s"), *(FString::SanitizeFloat(DeltaTime)));
		UE_LOG(LogTemp, Warning, TEXT("Spawn enemy"));

		FActorSpawnParameters SpawnParam;
		GetWorld()->SpawnActor<APaperEnemy>(PaperEnemy0, FVector(0, 0, 400), FRotator::ZeroRotator, SpawnParam);

		secondsCount = 0.0f;
	}

	secondsCount += DeltaTime;
}