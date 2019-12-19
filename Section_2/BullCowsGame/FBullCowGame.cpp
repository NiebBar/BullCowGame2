#include "FBullCowGame.h"

using int32 = int;

FBullCowGame::FBullCowGame() 
{
	Reset();
}

int32 FBullCowGame::GetMaxTries() const { return MyMaxTries; }

int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }

void FBullCowGame::Reset()
{
	constexpr int32 MAX_TRIES = 8;
	MyMaxTries = MAX_TRIES;

	const FString HIDDEN_WORD = "PizzaPlanet";
	MyHiddenWord = HIDDEN_WORD;

	MyCurrentTry = 1;

	return;
}

bool FBullCowGame::IsGameWon() const
{
	return false;
}

bool FBullCowGame::CheckGuessValidity(FString)
{
	return false;
}

//recives a valid guess, incriments turns and returns count
BullCowCount FBullCowGame::SubmitGuess(FString)
{
	/*bedzie robic duzo rzeczy, czy w tej skali to juz god object? */
	MyCurrentTry++;
	BullCowCount BullCowCount;



	return BullCowCount;
}
