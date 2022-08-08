// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SpcPlayerController.h"
#include "GameFramework/Actor.h"
#include "SpcBulletController.generated.h"

UCLASS()
class SPC_API ASpcBulletController : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASpcBulletController();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere)
	TMap<FName, UPaperSprite*> sprites;

};
