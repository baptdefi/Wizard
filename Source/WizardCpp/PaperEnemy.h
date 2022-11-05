// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Enums.h"

#include "CoreMinimal.h"
#include "PaperCharacter.h"
#include "PaperEnemy.generated.h"

/**
 * 
 */
UCLASS()
class WIZARDCPP_API APaperEnemy : public APaperCharacter
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly)
	Types EnemyType;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);
};
