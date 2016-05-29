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

	
	for (TObjectIterator<UObject> it; it; ++it)
	{
		UObject* currentObject = *it;
		UE_LOG(LogTemp, Log, TEXT("Found UObject named: %s"), *(currentObject->GetName()));
	}

	
	/*APlayerController* MyPC = GetMyPlayerControllerFromSomewhere();
	UWorld World = MyPC->GetWorld();
	for (TActorIterator<AFloatingActor> it(World); it; ++it)
	{
		AActor* currentActor = *it;
		UE_LOG(LogTemp, Log, TEXT("Found AActor named: %s"), *(currentActor->GetName()));
	}*/





	//UE_LOG(LogTemp, Log, TEXT("Found UObject named: %s"), *this->GetName());
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

//void AFloatingActor::CalledFromCpp_Implementation()
//{
//	//내용 구현
//}


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

	

	
	//UE_LOG(LogTemp, Log, TEXT("Found UObject named: %s"), TEXT("why") );

}

