/*This is some silly text to introudce
this type of a comment*/
#include <iostream>
#include <string>
#include "FBullCowGame.h"

using FText = std::string;
using int32 = int;

void PrintIntro();
void PlayGame();
FText GetValidGuess();
bool AskToPlayAgain();

FBullCowGame BCGame; //instance of a new game

//the entry point of aplication
int main()
{
	std::cout << BCGame.GetCurrentTry();

	bool bPlayAgain = false;
	do {
		PrintIntro();
		PlayGame();
		bPlayAgain = AskToPlayAgain();

	} 
	while (bPlayAgain);

	std::cout << std::endl;
	return 0; //exit the aplication
}

//intro
void PrintIntro() 
{

	std::cout << "Welcome to Bu11s and Cows, a fun word game.\n";
	std::cout << "Can you guess the " << BCGame.GetHiddenWordLength();
	std::cout << "letter isogram I'm thinking of?\n";
	std::cout << std::endl;
	return;
}

	void PlayGame() 
	{

		BCGame.Reset();
		int32 MaxTries = BCGame.GetMaxTries();
		
		//loop for the number of turns asking for guesses
		
		constexpr int32 NUMBER_OF_TURNS = 5;
	
		for (int32 count = 1; count <= NUMBER_OF_TURNS; count++) {
			FText Guess = GetValidGuess();

			



		//submit valid quqess to the game and recive counts
		FBullCowCount BullCowCount = BCGame.SubmitGuess(Guess);

		std::cout << "Bulls = " << BullCowCount.Bulls;
		std::cout << "Cows = " << BullCowCount.Cows << "\n\n";

		}

	}

	//loop jakostam untill the user gives a valid guess
	FText GetValidGuess()
	{ 
		EGuessStatus Status = EGuessStatus::Invalid_Status;
		do {

			//get a guess from the player
			int32 CurrentTry = BCGame.GetCurrentTry();
			std::cout << " Try " << CurrentTry << ". Enter your guess: ";
			FText Guess = "";
			std::getline(std::cin, Guess);



			 Status = BCGame.CheckGuessValidity(Guess);

			switch (Status)
			{
			case EGuessStatus::Wrong_Length:
				std::cout << "Please enter a " << BCGame.GetHiddenWordLength() << "letter word.\n";
				break;

			case EGuessStatus::Not_Isogram:
				std::cout << "Please enter a word without repeating letters\n";
				break;
			case EGuessStatus::Not_Lewercase:
				std::cout << "Please enter all lower case letters.\n";
				break;
			default:
				return Guess;
			}
			std::cout << std::endl;
		} while (Status != EGuessStatus::OK); //keep loopin until we get no errors


	

}

	bool AskToPlayAgain()
	{
		std::cout << "Do you want to play again (y/n)?";
		FText Response = "";
		std::getline(std::cin, Response);
		//std::cout << "Is it y" << (Response[0] == 'y');
		return (Response[0] == 'y')|| (Response[0] == 'Y');
	}
