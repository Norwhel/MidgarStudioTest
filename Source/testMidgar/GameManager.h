// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TBTCharacter.h"
#include "TurnManager.h"
#include "GameManager.generated.h"

UCLASS()
class TESTMIDGAR_API AGameManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGameManager();

	// Must be filled in-level, next developement could be to fill this array with pre-prepared Data Tables files
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<ATBTCharacter*> enemyList;

	// Must be filled in-level, next developement could be to fill this array with pre-prepared Data Tables files
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<ATBTCharacter*> playerCharatersList;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
