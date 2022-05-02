// Fill out your copyright notice in the Description page of Project Settings.


#include "TurnManager.h"

// Sets default values
ATurnManager::ATurnManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATurnManager::BeginPlay()
{
	Super::BeginPlay();
	
}

//Before combat---------

// Called before the start of the fight, sorts the given fighters list based on their speed (The character with highest speed is placed at index 0, the one with lowest speed at last index).
void ATurnManager::SortFighters()
{
	ATBTCharacter* highestSpeedCharacter;
	TArray<ATBTCharacter*> sortedList;
	TArray<ATBTCharacter*> unsortedList = fightersList;
	while (fightersList.Num() != sortedList.Num())
	{
		highestSpeedCharacter = unsortedList[0];
		for (ATBTCharacter* character : unsortedList)
		{
			if (character->speed > highestSpeedCharacter->speed)
				highestSpeedCharacter = character;
		}
		sortedList.Add(highestSpeedCharacter);
		unsortedList.Remove(highestSpeedCharacter);
	}
	fightersList = sortedList;
}

//Turn by turn management--------

// Called when combat begin to start the rotation of turn
void ATurnManager::StartFight()
{
	fightersArrayLength = fightersList.Num();
	currentFighterNumber = 0;
	StartTurn();
}

// Call the character to play his turn. Then TurnManager waits for current playing character to play his turn.
void ATurnManager::StartTurn()
{
	currentFighter = fightersList[currentFighterNumber];
	if (currentFighter->dead == true)
	{
		NextCharacterTurn();
	}
	else
	{
		currentFighter->PlayTurn();
	}
}

// Called by the character when it did play his turn. 
void ATurnManager::TurnPlayed()
{
	currentFighter->EndTurn();
	if (gameEnded == false)
	{
		NextCharacterTurn();
	}
}

// Take the next character in the file to start back the turn process.
void ATurnManager::NextCharacterTurn()
{
	currentFighterNumber++;
	if (currentFighterNumber >= fightersArrayLength)
	{
		currentFighterNumber = 0;
	}
	StartTurn();
}

// Called when the combat ends.
void ATurnManager::EndGame()
{
	gameEnded = true;
}

// Called every frame
void ATurnManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

