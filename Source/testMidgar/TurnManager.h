// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TBTCharacter.h"
#include "TurnManager.generated.h"

UCLASS()
class TESTMIDGAR_API ATurnManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATurnManager();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<ATBTCharacter*> fightersList;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ATBTCharacter* currentFighter;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 fightersArrayLength;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 currentFighterNumber;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool gameEnded;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable)
	void SortFighters();

	UFUNCTION(BlueprintCallable)
	void StartFight();

	UFUNCTION(BlueprintCallable)
	void StartTurn();

	UFUNCTION(BlueprintCallable)
	void TurnPlayed();

	UFUNCTION(BlueprintCallable)
	void NextCharacterTurn();

	UFUNCTION(BlueprintCallable)
	void EndGame();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
