// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SpcBullet.h"
#include "SpcSpacecraftBase.h"
#include "SpcSpacecraft.generated.h"

/**
 * 
 */
UCLASS()
class SPC_API ASpcSpacecraft : public ASpcSpacecraftBase
{
	GENERATED_BODY()

public:
	ASpcSpacecraft();

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, Category="Bullet")
	TSubclassOf<ASpcBullet> bullet;
};
