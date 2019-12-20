#include "FBullCowGame.h"
#include <map>
#define TMap std::map

using int32 = int;

FBullCowGame::FBullCowGame() 
{
	Reset();
}

int32 FBullCowGame::GetMaxTries() const { return MyMaxTries; }
int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }
int32 FBullCowGame::GetHiddenWordLength() const { return MyHiddenWord.length(); }
bool FBullCowGame::IsGameWon() const { return bGameIsWon; }

void FBullCowGame::Reset()
{
	constexpr int32 MAX_TRIES = 8;
	const FString HIDDEN_WORD = "planet";
	
	MyMaxTries = MAX_TRIES;
	MyHiddenWord = HIDDEN_WORD;

	MyCurrentTry = 1;
	bGameIsWon = false;

	return;
}

EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess) const
{
	if (!IsIsogram(Guess))//if the guess isn't an isogram
	{
		return EGuessStatus::Not_Isogram; //TODO write function
	}
	else if (false) //if the guess isn't all lowercase
	{
		return EGuessStatus::Not_Lewercase; //TODO write function
	}
	else if (Guess.length() != GetHiddenWordLength())//if the guess length is wrong
	{
		return EGuessStatus::Wrong_Length;
	}

	else 
	{
		return EGuessStatus::OK;
	}
	
}

//recives a valid guess, incriments turns and returns count
FBullCowCount FBullCowGame::SubmitValidGuess(FString Guess)
{
	/*bedzie robic duzo rzeczy, czy w tej skali to juz god object? */
	MyCurrentTry++;
	FBullCowCount BullCowCount;
	int32 WordLength = MyHiddenWord.length(); // ASSuming same length as guess

	for (int32 MHWChar = 0; MHWChar < WordLength; MHWChar++) {
	
		for (int32 GChar = 0; GChar < WordLength; GChar++){

			if (Guess[GChar] == MyHiddenWord[MHWChar]) {
			
				if (MHWChar == GChar) {
					BullCowCount.Bulls++;
				}
			
				else {
					BullCowCount.Cows++;
				}


			}


		}


	}

	if (BullCowCount.Bulls == WordLength) {
		bGameIsWon = true;
	}
	else 
	{
		bGameIsWon = false;
	}

	return BullCowCount;
}

bool FBullCowGame::IsIsogram(FString Word) const
{

	//treat 0 and 1 letter words as isogram
	if (Word.length() <= 1) { return true; }

	TMap<char, bool> LetterSeen; //setup our map
	for (auto Letter : Word) //for all letters of the word 
	{

		Letter = tolower(Letter);
		if (LetterSeen[Letter]) {//if the letter is in the map
			return false; //we do NOT have an isogram
		}
		else {
			LetterSeen[Letter] = true; //ad the letter to the map as seen
		}
	}
	return true; //for example in case where /0 is entered
}
