// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SpcSpacecraft.h"
#include "GameFramework/PlayerController.h"
#include "SpcPlayerControllerBase.generated.h"

/**
 * 
 */
UCLASS()
class SPC_API ASpcPlayerControllerBase : public APlayerController
{
	GENERATED_BODY()

public:
	ASpcPlayerControllerBase();

	virtual void BeginPlay() override;
	virtual void PlayerTick(float DeltaTime) override;
	virtual void SetupInputComponent() override;

	void MoveForward(float Value);
	void MoveRight(float Value);

	void Attack();
	void EndAttack();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float ImpulseSpacecraft = 500.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float ImpulseBullet = 500.0f;

protected:
	ASpcSpacecraft* Spacecraft{nullptr};
};
