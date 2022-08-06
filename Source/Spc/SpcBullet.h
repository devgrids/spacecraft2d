// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PaperSpriteComponent.h"
#include "GameFramework/Actor.h"
#include "SpcBullet.generated.h"

class UPaperSprite;
UCLASS()
class SPC_API ASpcBullet : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ASpcBullet();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UPaperSpriteComponent* SpriteComponent{nullptr};

	UPROPERTY(EditAnywhere)
	TMap<FName, UPaperSprite*> bullet;

	UFUNCTION()
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp,
						int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
};
