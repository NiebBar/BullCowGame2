
#include <iostream>
#include <string>
#include "FBullCowGame.h"

void PrintIntro();
void PlayGame();
std::string GetGuess();
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

	} while (bPlayAgain);

	std::cout << std::endl;
	return 0; //exit the aplication
}

//intro
void PrintIntro() {

	constexpr int WORLD_LENGTH = 9;

	std::cout << "Welcome to Bu11s and Cows, a fun word game.\n";
	std::cout << "Can you guess the " << WORLD_LENGTH;
	std::cout << "letter isogram I'm thinking of?\n";
	std::cout << std::endl;
	return;
}

	void PlayGame() 
	{

		
		
		
		int MaxTries = BCGame.GetMaxTries();

		//loop for the number of turns asking for guesses
		
	
		for (int count = 1; count <= MaxTries; count++) {
			std::string Guess = GetGuess();
			std::cout << "Your guess was: " << Guess << std::endl;
			std::cout << std::endl;
		}

	}

	std::string GetGuess()
	{
		int CurrentTry = BCGame.GetCurrentTry();

	//get a guess from the player
		std::cout <<  " Try " << CurrentTry << ". Enter your guess: ";
		std::string Guess = "";
		std::getline(std::cin, Guess);
		return Guess;

}

	bool AskToPlayAgain()
	{
		std::cout << "Do you want to play again (y/n)?";
		std::string Response = "";
		std::getline(std::cin, Response);
		//std::cout << "Is it y" << (Response[0] == 'y');
		return (Response[0] == 'y')|| (Response[0] == 'Y');
	}
