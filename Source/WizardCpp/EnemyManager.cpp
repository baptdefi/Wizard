// Fill out your copyright notice in the Description page of Project Settings.

#include "Kismet/KismetMathLibrary.h"

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

		int Random = UKismetMathLibrary::RandomIntegerInRange(0, 4);
		TSubclassOf<class APaperEnemy> EnemyToSpawn = PaperEnemy0;

		switch (Random)
		{
		case 0:
			EnemyToSpawn = PaperEnemy0;
			break;
		case 1:
			EnemyToSpawn = PaperEnemy1;
			break;
		case 2:
			EnemyToSpawn = PaperEnemy2;
			break;
		case 3:
			EnemyToSpawn = PaperEnemy3;
			break;
		case 4:
			EnemyToSpawn = PaperEnemy4;
			break;
		default:
			break;
		}

		FActorSpawnParameters SpawnParam;
		GetWorld()->SpawnActor<APaperEnemy>(EnemyToSpawn, FVector(0, 0, 400), FRotator::ZeroRotator, SpawnParam);

		secondsCount = 0.0f;
	}

	secondsCount += DeltaTime;
}