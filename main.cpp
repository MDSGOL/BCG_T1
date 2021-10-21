/* This is the console executable, that makes use of the BullCow class this acts as the view in a MVC pattern, and is responsible for all user interaction.
For game logic, see the FBullCow class. */

#include <iostream>
#include <string>
#include "FBullzAndCowz.h"
#include <vector>
using FText = std::string;
using FString = std::string;
using int32 = int;

/*First, globally initialize all functions in main.cpp so any function is callable from anywhere in the code.
Functions end in parenthesis (just like methods) and can be called like a variable such as global HintButton.
This means that functions can be created for each individual part and simply be added anywhere into the code. */
int32 SelectDifficulty();
void PlayGame();
FString RetreiveGuess();
bool AskRematch();

//Globalized (on / off) buttons
FString HintButtonFs;
FString TwoButtonFs;
FString BonusButtonFs;

//(Globally) instntiate class containing the getMethods()
FBullCow BCGame;

//Runs the game
int32  main(void)
{
	do
	{
		PlayGame();
	} while (AskRematch() == 1);
	return 0;
}

void PlayGame()
{
	//starts entire game with SelectDifficulty();
	int32 MaxLimit = SelectDifficulty();

	//instantiate each player's bulls & cows to the struct in the header file
	FBullCowCount BullCowCount;
	FBullCowCount BullCowCountTwo;

	FString GuessOne;
	int32 GuessNumber;

	//Loops a max limit of Max_Guesses from SelectDifficulty() so users have limted guesses
	for (GuessNumber = 1; GuessNumber <= MaxLimit; GuessNumber++)
	{
		std::cout << "\nAttempt number " << GuessNumber << " of " << MaxLimit << ':' << std::endl;

		// if (one player)
		if (BCGame.getTwoButton(TwoButtonFs) == false)
		{
			//Runs retreive_guess function to ensure the guess is valid
			GuessOne = RetreiveGuess();

			//Compares valid guess to hidden_word
			BullCowCount = BCGame.SubmitGuess(GuessOne, HintButtonFs, BonusButtonFs);

			//Ends the game if bulls match the hidden word length
			if (BullCowCount.BullsNumber == BCGame.getHiddenWordLength())
			{
				std::cout << "\nYou rock!\n"; return;
			}
		}

		//if (two player)
		else if (BCGame.getTwoButton(TwoButtonFs) == true)
		{
			//Runs retrieve_guess function to ensure guess is valid
			std::cout << "\nGo ahead Player 1, ";
			GuessOne = RetreiveGuess();

			//Compares valid guess to hidden_word
			BullCowCount = BCGame.SubmitGuess(GuessOne, HintButtonFs, BonusButtonFs);

			//Ends the game if bulls match the hidden_word length
			if (BullCowCount.BullsNumber == BCGame.getHiddenWordLength())
			{
				std::cout << "\nYou rock! \n"; return;
			}

			//Player 2's turn
			std::cout << "\nIt's your turn Player 2, ";
			FString GuessTwo = RetreiveGuess();
			BullCowCountTwo = BCGame.SubmitGuess(GuessTwo, HintButtonFs, BonusButtonFs);

			//Ends the game if bulls match the hidden_word length
			if (BullCowCountTwo.BullsNumber == BCGame.getHiddenWordLength())
			{
				std::cout << "\nYou rock!\n"; return;
			}
		}
	}
	//Better luck next time!
	if (BullCowCount.BullsNumber != BCGame.getHiddenWordLength() && BullCowCountTwo.BullsNumber != BCGame.getHiddenWordLength())
		std::cout << "\nYour isogram was " << BCGame.getHiddenWord() << ". \nBetter luck next time :( \n";
	return;
}

//Introduction: Greater difficulty = longer word length && more guesses
int32 SelectDifficulty()
{
	std::cout << "\nWelcome to Bullz & Cowz!\n";
	std::cout << std::endl;
	std::cout << "          }   {         ___ " << std::endl;
	std::cout << "          (o o)        (o o) " << std::endl;
	std::cout << "   /-------\\ /          \\ /-------\\ " << std::endl;
	std::cout << "  / | BULL |O            O| COW  | \\ " << std::endl;
	std::cout << " *  |-,--- |              |------|  * " << std::endl;
	std::cout << "    ^      ^              ^      ^ " << std::endl;

	std::cout << "\nAn isogram is a word or phrase without repeating letters.\nLet's see if you can guess the hidden isogram. \n";

	std::cout << "\nHints are provided by default.\nType 'off' to remove hints or press enter to continue. ";
	std::getline(std::cin, HintButtonFs);

	std::cout << "\nThis game is one player by default.\nFor an additional player, type 'two' or press enter to continue. ";
	std::getline(std::cin, TwoButtonFs);

	std::cout << "\nPlease select your difficulty\n(Novice, Normal, Never): ";
	FText Difficulty;
	std::getline(std::cin, Difficulty);
	BCGame.Reset(Difficulty);

	//Makes difficulty response lowercase
	for (int32 i = 0; i < Difficulty.length(); i++)
	{
		Difficulty[i] = tolower(Difficulty[i]);
	}

	//Determines user's amount of guesses
	int32 Max_Guesses;
	if (Difficulty == "novice")
	{
		if (BCGame.getTwoButton(TwoButtonFs)) { Max_Guesses = 4; }
		else Max_Guesses = 8;
	}
	else if (Difficulty == "normal")
	{
		if (BCGame.getTwoButton(TwoButtonFs)) { Max_Guesses = 6; }
		else Max_Guesses = 12;
	}
	else if (Difficulty == "never")
	{
		if (BCGame.getTwoButton(TwoButtonFs)) { Max_Guesses = 8; }
		else Max_Guesses = 16;
	}

	//Loops invalid difficulty selection
	else while (Difficulty != "novice" || Difficulty != "normal" || Difficulty != "never")
	{
		std::cout << "\nPlease select a Difficulty (Novice, Normal, Never)\n";
		std::getline(std::cin, Difficulty);
		BCGame.Reset(Difficulty);

		for (int32 i = 0; i < Difficulty.length(); i++)
		{
			Difficulty[i] = tolower(Difficulty[i]);
		}

		if (Difficulty == "novice")
		{
			if (BCGame.getTwoButton(TwoButtonFs)) { Max_Guesses = 4; break; }
			else Max_Guesses = 8; break;
		}
		else if (Difficulty == "normal")
		{
			if (BCGame.getTwoButton(TwoButtonFs)) { Max_Guesses = 6; break; }
			else Max_Guesses = 12; break;
		}
		else if (Difficulty == "never")
		{
			if (BCGame.getTwoButton(TwoButtonFs)) { Max_Guesses = 8; break; }
			else Max_Guesses = 16; break;
		}
	}

	std::cout << "\nYou have selected " << Difficulty << '.' << std::endl;
	std::cout << "\nYour isogram is " << BCGame.getHiddenWordLength() << " letters long.";
	std::cout << "\nYou will have " << Max_Guesses << " attempts.\n";

	int32 const BonusRequirement = 7;
	if (BCGame.getHiddenWordLength() >= BonusRequirement)
	{
		std::cout << "\nThis is a large isogram. Would you like a bonus hint?\n";
		std::getline(std::cin, BonusButtonFs);

		if (BCGame.getBonusButton(BonusButtonFs))
		{
			BCGame.runBonusHint();
		}
	}
	//Max_Guesses goes into Max_Limit amount of playGame() function
	return Max_Guesses;
}

FString RetreiveGuess()
{
	FString Guess;
	std::cout << "\nTake your best guess: ";
	std::getline(std::cin, Guess);

	//Checks guess validity from the enumeration class (EGuessStatus)
	EGuessStatus Status = BCGame.CheckGuessValidity(Guess);

	do {
		if (Status == EGuessStatus::Incorrect_length)
		{
			std::cout << "\nPlease make your guess " << BCGame.getHiddenWordLength() << " letters long.\n";
			std::getline(std::cin, Guess);
			Status = BCGame.CheckGuessValidity(Guess);
		}

		if (Status == EGuessStatus::Not_an_isogram)
		{
			std::cout << "\nPlease enter an isogram.\n";
			std::getline(std::cin, Guess);
			Status = BCGame.CheckGuessValidity(Guess);
		}

		if (Status == EGuessStatus::Incorrect_capitalization)
		{
			std::cout << "\nPlease adjust your answer with proper capitalization.\n";
			std::getline(std::cin, Guess);
			Status = BCGame.CheckGuessValidity(Guess);
		}

		if (Status == EGuessStatus::Valid_entry)
		{
			break;
		}
	} while (Status != EGuessStatus::Valid_entry);

	//Turn all guesses into lowercase //this could be taken out if game was ever too heavy because capitalization won't make it through validation anyways
	for (int32 i = 0; i < Guess.length(); i++)
	{
		Guess[i] = tolower(Guess[i]);
	}
	return Guess;
}

bool AskRematch()
{
	std::cout << "\nWould you like to play again? \n (Y/N):  ";
	FText Response;
	std::getline(std::cin, Response);

	if (Response[0] == 'Y' || Response[0] == 'y') { return true; }
	else while (Response[0] != 'Y' || Response[0] != 'y')
	{
		std::cout << "\nWould you like to give it another shot? (Y/N) :  ";
		FText Response;
		std::getline(std::cin, Response);
		if (Response[0] == 'Y' || Response[0] == 'y') { return true; }
	}
}


