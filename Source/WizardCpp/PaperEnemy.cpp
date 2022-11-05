// Fill out your copyright notice in the Description page of Project Settings.


#include "PaperEnemy.h"

// Called when the game starts or when spawned
void APaperEnemy::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void APaperEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (secondsCount >= 20)
	{
		UE_LOG(LogTemp, Warning, TEXT("Death"));

		Destroy();
	}

	secondsCount += DeltaTime;
}

