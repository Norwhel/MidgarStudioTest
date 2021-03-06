// Fill out your copyright notice in the Description page of Project Settings.


#include "TBTCharacter.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
ATBTCharacter::ATBTCharacter()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BodyMesh = CreateDefaultSubobject<UStaticMeshComponent>("BodyMesh");
	SetRootComponent(BodyMesh);

	//Init base values
	maxhealth = 10.0f;
	speed = 5.0f;

}

// Called when the game starts or when spawned
void ATBTCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATBTCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}