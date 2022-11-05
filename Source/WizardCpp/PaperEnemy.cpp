// Fill out your copyright notice in the Description page of Project Settings.

#include "WizardCppProjectile.h"
#include "Components/CapsuleComponent.h"
#include "Kismet/KismetMathLibrary.h"

#include "PaperEnemy.h"

// Called when the game starts or when spawned
void APaperEnemy::BeginPlay()
{
	Super::BeginPlay();

	GetCapsuleComponent()->OnComponentHit.AddDynamic(this, &APaperEnemy::OnHit);
}

// Called every frame
void APaperEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector PlayerLocation = GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorLocation();
	FVector EnemytoPlayer = PlayerLocation - GetActorTransform().GetLocation();
	EnemytoPlayer.Normalize();

	FRotator NewRotation = UKismetMathLibrary::MakeRotFromXZ(EnemytoPlayer, FVector(0, 0, 1));
	SetActorRotation(NewRotation);

	FVector NewLocation = GetActorTransform().GetLocation() + EnemytoPlayer * 0.5f;
	SetActorLocation(NewLocation);
}

void APaperEnemy::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	if (OtherActor == GetWorld()->GetFirstPlayerController()->GetPawn())
	{
		UE_LOG(LogTemp, Warning, TEXT("Player Death"));
		Destroy();
	}

	if (OtherActor->GetClass()->IsChildOf(AWizardCppProjectile::StaticClass()))
	{
		AWizardCppProjectile* Projectile = Cast<AWizardCppProjectile>(OtherActor);
		if (Projectile->ProjectileType == EnemyType)
		{
			UE_LOG(LogTemp, Warning, TEXT("Projectile Death"));
			Destroy();
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("Wrong Projectile"));
		}
	}
}

