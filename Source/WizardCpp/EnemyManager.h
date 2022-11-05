// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "PaperEnemy.h"

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EnemyManager.generated.h"

/**
 * 
 */
UCLASS(BlueprintType)
class WIZARDCPP_API AEnemyManager : public AActor
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<class APaperEnemy> PaperEnemy0;
	
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<class APaperEnemy> PaperEnemy1;
	
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<class APaperEnemy> PaperEnemy2;
	
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<class APaperEnemy> PaperEnemy3;
	
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<class APaperEnemy> PaperEnemy4;

	// Sets default values for this actor's properties
	AEnemyManager();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	float secondsCount = 0.0f;
	
};
