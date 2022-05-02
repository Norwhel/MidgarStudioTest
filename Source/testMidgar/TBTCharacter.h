// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TBTCharacter.generated.h"

UCLASS()
class TESTMIDGAR_API ATBTCharacter : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATBTCharacter();

	UPROPERTY(EditAnywhere, Category = "Components")
	class UStaticMeshComponent* BodyMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float maxhealth;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float speed;

	UPROPERTY(BlueprintReadWrite)
	bool dead;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//implement the actions of the character during his turn
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void PlayTurn();

	//implement the actions of the character during the end of his turn
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void EndTurn();

};
