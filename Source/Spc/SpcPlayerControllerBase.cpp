// Fill out your copyright notice in the Description page of Project Settings.


#include "SpcPlayerControllerBase.h"

#include "Kismet/GameplayStatics.h"
#include "Math/UnitConversion.h"

ASpcPlayerControllerBase::ASpcPlayerControllerBase()
{
}

void ASpcPlayerControllerBase::BeginPlay()
{
	Super::BeginPlay();

	Spacecraft = Cast<ASpcSpacecraft>(UGameplayStatics::GetPlayerPawn(GetWorld(), 0));
	if (IsValid(Spacecraft))
	{
		UE_LOG(LogTemp, Warning, TEXT("Valid"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Not Valid"));
	}
}

void ASpcPlayerControllerBase::PlayerTick(float DeltaTime)
{
	Super::PlayerTick(DeltaTime);
}

void ASpcPlayerControllerBase::SetupInputComponent()
{
	Super::SetupInputComponent();

	InputComponent->BindAction("Attack", IE_Pressed, this, &ASpcPlayerControllerBase::Attack);
	InputComponent->BindAction("Attack", IE_Released, this, &ASpcPlayerControllerBase::EndAttack);

	InputComponent->BindAxis("MoveForward", this, &ASpcPlayerControllerBase::MoveForward);
	InputComponent->BindAxis("MoveRight", this, &ASpcPlayerControllerBase::MoveRight);
}

void ASpcPlayerControllerBase::MoveForward(float Value)
{
	if (Value != 0)
	{
		const FVector VecVelocity = Spacecraft->SpriteComponent->GetComponentVelocity();
		const float velocity = VecVelocity.Length();

		Spacecraft->SpriteComponent->AddImpulse(FVector(0, 0, Value * ImpulseSpacecraft));
		// UE_LOG(LogTemp, Warning, TEXT("MoveForward"));
	}
}

void ASpcPlayerControllerBase::MoveRight(float Value)
{
	if (Value != 0)
	{
		const FVector VecVelocity = Spacecraft->SpriteComponent->GetComponentVelocity();
		const float velocity = VecVelocity.Length();

		Spacecraft->SpriteComponent->AddImpulse(FVector(0, Value * ImpulseSpacecraft, 0));
		// UE_LOG(LogTemp, Warning, TEXT("Vel: %f"), velocity);
	}
}

void ASpcPlayerControllerBase::Attack()
{
	UE_LOG(LogTemp, Warning, TEXT("Attack"));
	const ASpcBullet* NewBullet = GetWorld()->SpawnActor<ASpcBullet>(Spacecraft->bullet,
	                                                                 Spacecraft->SpriteComponent->GetComponentLocation() +
	                                                                 FVector(0, 0, 25),
	                                                                 Spacecraft->SpriteComponent->GetComponentRotation());

	NewBullet->SpriteComponent->AddImpulse(FVector(0, 0, ImpulseBullet));
}

void ASpcPlayerControllerBase::EndAttack()
{
	UE_LOG(LogTemp, Warning, TEXT("End Attack"));
}
