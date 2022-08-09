// Fill out your copyright notice in the Description page of Project Settings.


#include "SpcBullet.h"

// Sets default values
ASpcBullet::ASpcBullet()
{
	SpriteComponent = CreateDefaultSubobject<UPaperSpriteComponent>(TEXT("SpriteComponent"));
}

// Called when the game starts or when spawnedda s
void ASpcBullet::BeginPlay()
{
	Super::BeginPlay();

	SpriteComponent->OnComponentBeginOverlap.AddDynamic(this, &ASpcBullet::OnOverlapBegin);

	Tags.Add("Bullet.Small");
}

// Called every frame
void ASpcBullet::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ASpcBullet::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp,
                                int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	// UE_LOG(LogTemp, Warning, TEXT("DESTROY BULLET"));
	Destroy();
}
