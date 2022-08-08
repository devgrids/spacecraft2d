// Fill out your copyright notice in the Description page of Project Settings.


#include "SpcSpacecraftBase.h"

#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"


ASpcSpacecraftBase::ASpcSpacecraftBase()
{
	SpcRoot = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComponent"));
	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComponent"));
	SpriteComponent = CreateDefaultSubobject<UPaperSpriteComponent>(TEXT("SpriteComponent"));

	RootComponent = SpcRoot;

	CameraBoom->SetupAttachment(SpcRoot);
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	


	SpriteComponent->SetupAttachment(SpcRoot);
}


// Called when the game starts or when spawned
void ASpcSpacecraftBase::BeginPlay()
{
	Super::BeginPlay();

	// SphereComponent->OnComponentBeginOverlap.AddDynamic(this, &ASpcSpacecraftBase::OnOverlapBegin);
	// SphereComponent->OnComponentEndOverlap.AddDynamic(this, &ASpcSpacecraftBase::OnOverlapEnd);
}

// Called every frame
void ASpcSpacecraftBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ASpcSpacecraftBase::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
                                        UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep,
                                        const FHitResult& SweepResult)
{
}

void ASpcSpacecraftBase::OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
                                      UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
}
