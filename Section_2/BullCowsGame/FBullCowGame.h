#pragma once
#include <string>

using FString = std::string;

using int32 = int;


struct BullCowCount
{
	int32 Bulls = 0;
	int32 Cows = 0;

};

class FBullCowGame {
public:
	FBullCowGame(); //constructor
		int32 GetMaxTries() const;
		int32 GetCurrentTry() const;
		bool IsGameWon() const;

		void Reset(); //more rich return value
		bool CheckGuessValidity (FString);
		BullCowCount SubmitGuess(FString);

//Pfadhfahflalskfd ffhal  fh
private:
	//see constructor
	int MyCurrentTry;
	int32 MyMaxTries;
	FString MyHiddenWord;
};