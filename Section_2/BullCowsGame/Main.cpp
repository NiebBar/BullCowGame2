/*This is some silly text to introudce
this type of a comment*/
#include <iostream>
#include <string>
#include "FBullCowGame.h"

using FText = std::string;
using int32 = int;

void PrintIntro();
void PlayGame();
FText GetGuess();
bool AskToPlayAgain();

FBullCowGame BCGame; //instance of a new game

//the entry point of aplication
int main()
{
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

	constexpr int WORLD_LENGTH = 9;

	std::cout << "Welcome to Bu11s and Cows, a fun word game.\n";
	std::cout << "Can you guess the " << WORLD_LENGTH;
	std::cout << "letter isogram I'm thinking of?\n";
	std::cout << std::endl;
	return;
}

	void PlayGame() 
	{

		BCGame.Reset();
		int32 MaxTries = BCGame.GetMaxTries();
		
		//loop for the number of turns asking for guesses
		
	
		for (int32 count = 1; count <= MaxTries; count++) {
			FText Guess = GetGuess();

			//submit valid quqess to the game
			//print number of cows and bulls


			std::cout << "Your guess was: " << Guess << std::endl;
			std::cout << std::endl;

		}

	}

	FText GetGuess()
	{
		int32 CurrentTry = BCGame.GetCurrentTry();

	//get a guess from the player
		std::cout <<  " Try " << CurrentTry << ". Enter your guess: ";
		FText Guess = "";
		std::getline(std::cin, Guess);
		return Guess;

}

	bool AskToPlayAgain()
	{
		std::cout << "Do you want to play again (y/n)?";
		FText Response = "";
		std::getline(std::cin, Response);
		//std::cout << "Is it y" << (Response[0] == 'y');
		return (Response[0] == 'y')|| (Response[0] == 'Y');
	}
