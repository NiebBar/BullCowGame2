/*This is some silly text to introudce
this type of a comment*/
#pragma once

#include <iostream>
#include <string>
#include "FBullCowGame.h"

//to make syntax Unreal friendly
using FText = std::string;
using int32 = int;

//function prototypes as outside class
void PrintIntro();
void PlayGame();
FText GetValidGuess();
bool AskToPlayAgain();
void PrintGameSummery(); 

FBullCowGame BCGame; //instance of a new game, wich we reuse across plays

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

	std::cout << "\n\nWelcome to Bu11s and Cows, a fun word game.\n";
	std::cout << "Tu mial byc fajny obrazek\n";
	std::cout << "Can you guess the " << BCGame.GetHiddenWordLength();
	std::cout << " letter isogram I'm thinking of?\n";
	std::cout << std::endl;
	return;
}

	//play a single game to completion
	void PlayGame() 
	{

		BCGame.Reset();
		int32 MaxTries = BCGame.GetMaxTries();
		
		//loop asking for guesses while the game in NOT won
		//and there are still tries remaining
		while ( ! BCGame.IsGameWon() && BCGame.GetCurrentTry() <= MaxTries) {
			FText Guess = GetValidGuess();

		//submit valid quqess to the game and recive counts
		FBullCowCount BullCowCount = BCGame.SubmitValidGuess(Guess);

		std::cout << "Bulls = " << BullCowCount.Bulls;
		std::cout << "Cows = " << BullCowCount.Cows << "\n\n";

		}

		PrintGameSummery();

		return;
	}

	//loop jakostam untill the user gives a valid guess
	FText GetValidGuess()
	{ 
		FText Guess = "";
		EGuessStatus Status = EGuessStatus::Invalid_Status;
		do {

			//get a guess from the player
			int32 CurrentTry = BCGame.GetCurrentTry();
			std::cout << "Try " << CurrentTry << " of " << BCGame.GetMaxTries();
			std::cout << ". Enter your guess: ";
			std::getline(std::cin, Guess);



			 Status = BCGame.CheckGuessValidity(Guess);

			switch (Status)
			{
			case EGuessStatus::Wrong_Length:
				std::cout << "Please enter a " << BCGame.GetHiddenWordLength() << "letter word.\n\n";
				break;

			case EGuessStatus::Not_Isogram:
				std::cout << "Please enter a word without repeating letters\n\n";
				break;
			case EGuessStatus::Not_Lewercase:
				std::cout << "Please enter all lower case letters.\n\n";
				break;
			default:
				// ASSume the guess is valid
				break;
			}

		} while (Status != EGuessStatus::OK); //keep loopin until we get no errors
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

	void PrintGameSummery()
	{
		if (BCGame.IsGameWon())
		{
			std::cout << "No fajnie.\n";
		}
		else
		{
			std::cout << "Better luck next time.\n";
		}
	
	
	}
