#pragma once
#include <string>

class FBullCowGame {
public:
		
		int GetMaxTries() const;
		int GetCurrentTry() const;
		bool IsGameWon() const;

		void Reset(); //more rich return value
		bool CheckGuessValidity (std::string);
		

//Pfadhfahflalskfd ffhal  fh
private:
	int MyCurrentTry = 1;
	int MyMaxTries = 5;
};