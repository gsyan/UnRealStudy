// Fill out your copyright notice in the Description page of Project Settings.

#include "QuickStart.h"
#include "FloatingActor.h"


// Sets default values
AFloatingActor::AFloatingActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	TotalDamage = 200;
	DamageTimeInSeconds = 1.0f;

}

// Called when the game starts or when spawned
void AFloatingActor::BeginPlay()
{
	Super::BeginPlay();
}

void AFloatingActor::PostInitProperties()
{
	Super::PostInitProperties();
	CalculateDamagePerSecond();
}

void AFloatingActor::CalculateDamagePerSecond()
{
	DamagePerSecond = TotalDamage / DamageTimeInSeconds;
}

#if WITH_EDITOR
void AFloatingActor::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	CalculateDamagePerSecond();

	Super::PostEditChangeProperty(PropertyChangedEvent);
}
#endif

// Called every frame
void AFloatingActor::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

	FVector NewLocation = GetActorLocation();
	float DeltaHeight = (FMath::Sin(RunningTime + DeltaTime) - FMath::Sin(RunningTime));
	NewLocation.Z += DeltaHeight * 20.0f;       //높이에 20 을 곱합니다
	RunningTime += DeltaTime;
	SetActorLocation(NewLocation);

}

