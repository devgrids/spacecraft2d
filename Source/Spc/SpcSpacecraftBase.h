// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "GameFramework/Pawn.h"
#include "PaperSpriteComponent.h"
#include "Components/BoxComponent.h"
#include "Components/SphereComponent.h"
#include "SpcSpacecraftBase.generated.h"

UCLASS()
class SPC_API ASpcSpacecraftBase : public APawn
{
	GENERATED_BODY()

public:
	ASpcSpacecraftBase();

	// virtual void OnConstruction(const FTransform& Transform) override;
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	//*****************************************************************************
	// Interface
	//*****************************************************************************

	//*****************************************************************************
	// AI
	//*****************************************************************************

	//*****************************************************************************
	// Components
	//*****************************************************************************

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	USceneComponent* SpcRoot{nullptr};

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	class USpringArmComponent* CameraBoom{nullptr};

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	class UCameraComponent* FollowCamera{nullptr};

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UPaperSpriteComponent* SpriteComponent{nullptr};
	
	//*****************************************************************************

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FGameplayTag Tag;

	//*****************************************************************************

	UFUNCTION()
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp,
	                    int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	void OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp,
	                  int32 OtherBodyIndex);

	//*****************************************************************************


	FORCEINLINE USpringArmComponent* GetSpringArmComponent() const { return CameraBoom; }
	FORCEINLINE UCameraComponent* GetCameraComponent() const { return FollowCamera; }
};
