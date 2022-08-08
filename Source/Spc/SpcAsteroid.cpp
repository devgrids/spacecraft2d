// Fill out your copyright notice in the Description page of Project Settings.


#include "SpcAsteroid.h"

#include "EngineUtils.h"

// Sets default values
ASpcAsteroid::ASpcAsteroid()
{
	SpriteComponent = CreateDefaultSubobject<UPaperSpriteComponent>(TEXT("SpriteComponent"));
}

// Called when the game starts or when spawned
void ASpcAsteroid::BeginPlay()
{
	Super::BeginPlay();
	SpriteComponent->OnComponentBeginOverlap.AddDynamic(this, &ASpcAsteroid::OnOverlapBegin);

	Tags.Add(FName("Family"));

	if (ActorHasTag(FName("Family")))
	{
		UE_LOG(LogTemp, Warning, TEXT("Tag"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("No Tag"));
	}

	for (TActorIterator<AActor> ActorIterator(GetWorld()); ActorIterator; ++ActorIterator)
	{
		AActor* Actor = *ActorIterator;
		if (Actor && Actor != this && Actor->GetClass()->ImplementsInterface(ASpcAsteroid::StaticClass()))
		{
			for (FName Tag : Actor->Tags)
			{
				GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Cyan, Tag.ToString());
			}
		}
	}

}

void ASpcAsteroid::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);
}

// Called every frame
void ASpcAsteroid::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ASpcAsteroid::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
                                  UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep,
                                  const FHitResult& SweepResult)
{
}
