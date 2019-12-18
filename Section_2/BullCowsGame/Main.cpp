
#include <iostream>
#include <string>

using namespace std;

void PrintIntro();
string GetGuessAndPrintBack();

int main()


{
	//the entry point of aplication
	PrintIntro();
	

	//get a guess from the payer
	cout << "Enter your guess: ";
	string guess = ""; 
	getline(cin, guess);
	

	//repete the guess back to them
	cout << "Your guess wa: " << guess << endl;

	//get a guess from the payer
	cout << "Enter your guess: ";
	string Guess = "";
	getline(cin, guess);


	//repete the guess back to them
	cout << "Your guess was: " << guess << endl;


	//get a guess from the payer
	cout << "Enter your guess: ";
	getline(cin, guess);

	//repete the guess back to them
	cout << "Your guess was: " << guess << endl;

	//loop for the number of turns asking for quesses
	constexpr int NUMBER_OF_TURNS = 5;
	for (int count = 1; count <= NUMBER_OF_TURNS; count++)

	{

		GetGuessAndPrintBack();
		cout << endl;

	}

	cout << endl;


	//pizza
	return 0;
}

void PrintIntro() {

	//intro

	void PrintIntro() {
	
		constexpr int WORLD_LENGTH = 9;

		cout << "Welcome to Bu11s and Cows";
		cout << "Can you guess the " << WORLD_LENGT;
		cout << " letter I'm thinking of?/n";
		cout << endl;
		return;
		
	}

	string GetGuessAndPrintBack()
	{

	//get a guess from the player
		cout << "Enter your guess: ";
		string Guess = "";
		getline(cin, Guess);
		//print the guess back
		cout << "Your guess wa: " << endl;
		return Guess;

}