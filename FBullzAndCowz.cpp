#include "FBullzAndCowz.h"
#include <iostream>
#include <vector>
#include <random>
#include <fstream>	
#include <ctime>
/*FString IsogramGame::SelectIsogram()
{
	std::vector<FString> Dictionary = {
		"bye", "art", "car", "yam", "lab", "the", "cut", "lot", "lie", "par",
		"say", "pay", "may", "jam", "mit", "din", "was", "pot", "pie", "mar",
		"ray", "elf", "fly", "fit", "lit", "sin", "put", "rot", "cry", "coy",
		"sand", "pair", "raid", "care", "sock", "fair", "hair", "land", "walk", "talk", "expo", "wasp",
		"same", "dart", "this", "from", "suit", "acre", "ages", "bale", "bail", "fast",
		"felt", "fawn", "nape", "army", "navy", "sold", "soda", "soup", "wave", "yarn",
		"toads", "brick", "stick", "roads", "stand", "trick", "thick", "loads", "talks", "locks", "angel",
		"thing", "miles", "lives", "facts", "cloth", "dwarf", "empty", "trash", "envoy", "enact",
		"faith", "farms", "farce", "fairy", "laugh", "lingo", "litre", "march", "marsh", "swift",
		"jaunts", "abound", "tricks", "bricks", "crawls", "crowns", "around", "orgasm", "bounty", "gizmos",
		"travel", "wealth", "second", "curled", "loving", "belfry", "fables", "factor", "fairly", "famine", "bronze",
		"farces", "nailed", "nebula", "nickel", "muster", "buster", "myrtle", "nachos", "mythos", "phrase", "quartz",
		"jukebox", "ziplock", "lockjaw", "quickly", "crazily", "jaybird", "jackpot", "quicken", "quicker", "imports",
		"clothes", "polearm", "jockeys", "subject", "cliquey", "apricot", "anxiety", "domains", "dolphin", "exclaim",
		"fabrics", "factory", "haircut", "pulsing", "scourge", "schlump", "turbine", "wrongly", "wyverns", "yogurt",
		"isogram", "mindful",
	};*/

	//FBullCow::FBullCow() { true; } //(unused) constructor [connstructors are run before the gthe rest of the code begins]

int32 FBullCow::getHiddenWordLength() const { return MyHiddenWord.length(); }

int32 FBullCow::getDifficulty(FString Difficulty) const
{
	if (Difficulty == "novice") { return 0; }
	else if (Difficulty == "normal") { return 1; }
	else if (Difficulty == "never") { return 2; }
}

FString FBullCow::getHiddenWord() const { return MyHiddenWord; }

void const FBullCow::runBonusHint()
{
	int32 firstLetter = 0;
	int32 lastLetter = MyHiddenWord.size() - 1;
	int32 RandomNumber = rand();
	int32 FirstOrLast;

	if (RandomNumber % 2 == 0)
	{
		FirstOrLast = firstLetter;
	}
	else FirstOrLast = lastLetter;

	std::cout << "\nYour word either begins or ends with the letter " << MyHiddenWord[FirstOrLast] << ".\n";
	return;
}

const bool FBullCow::getBonusButton(FString Bonus) const
{
	if (Bonus[0] == 'Y' || Bonus[0] == 'y') { return true; }
	else return false;
}

/* //Perfectly working, isGameWon boolean. It was just unnecessary because of changes to main.cpp PlayGame() function
bool FBullCow::isGameWon(int32 GuessBullNumber) const
{
	if (GuessBullNumber == MyHiddenWord.length()) { return true; }
	else return false;
}*/

//Resets game
void FBullCow::Reset(FString Difficulty)
{
	if (FBullCow::getDifficulty(Difficulty) == 0)
	{
		FBullCow::NoviceIsogram();
	}

	else if (FBullCow::getDifficulty(Difficulty) == 1)
	{
		FBullCow::NormalIsogram();
	}

	else if (FBullCow::getDifficulty(Difficulty) == 2)
	{
		FBullCow::NeverIsogram();
	}
	return;
}

/*= {
"bye", "art", "car", "yam", "lab", "the", "cut", "lot", "lie", "par",
"say", "pay", "may", "jam", "mit", "din", "was", "pot", "pie", "mar",
"ray", "elf", "fly", "fit", "lit", "sin", "put", "rot", "cry", "coy",
"sand", "pair", "raid", "care", "sock", "fair", "hair", "land", "walk", "talk", "expo", "wasp",
"same", "dart", "this", "from", "suit", "acre", "ages", "bale", "bail", "fast",
"felt", "fawn", "nape", "army", "navy", "sold", "soda", "soup", "wave", "yarn",
"toads", "brick", "stick", "roads", "stand", "trick", "thick", "loads", "talks", "locks", "angel",
"thing", "miles", "lives", "facts", "cloth", "dwarf", "empty", "trash", "envoy", "enact",
"faith", "farms", "farce", "fairy", "laugh", "lingo", "litre", "march", "marsh", "swift",
"jaunts", "abound", "tricks", "bricks", "crawls", "crowns", "around", "orgasm", "bounty", "gizmos",
"travel", "wealth", "second", "curled", "loving", "belfry", "fables", "factor", "fairly", "famine", "bronze",
"farces", "nailed", "nebula", "nickel", "muster", "buster", "myrtle", "nachos", "mythos", "phrase", "quartz",
"jukebox", "ziplock", "lockjaw", "quickly", "crazily", "jaybird", "jackpot", "quicken", "quicker", "imports",
"clothes", "polearm", "jockeys", "subject", "cliquey", "apricot", "anxiety", "domains", "dolphin", "exclaim",
"fabrics", "factory", "haircut", "pulsing", "scourge", "schlump", "turbine", "wrongly", "wyverns", "yogurt",
"isogram", "mindful", }*/

void const FBullCow::NoviceIsogram()
{
	std::vector<FString> vNovice =
	{
		"history", "way", "art",

	};

	std::default_random_engine RandomGenerator(std::time(NULL));
	std::uniform_int_distribution<int32> randomIndex(0, vNovice.size());
	int32 RandNum = randomIndex(RandomGenerator);
	const FString RandomHiddenWord = vNovice.at(RandNum);
	MyHiddenWord = RandomHiddenWord;

	/*	std::ifstream NoviceFile("NoviceIsograms.txt2");
	if (NoviceFile)
	{
	FString line;
	std::vector<FString>vNovice(0);
	while (std::getline(NoviceFile, line))
	{
	if (NoviceFile)
	{
	vNovice.push_back(line);
	}
	}

	std::uniform_int_distribution<int32> randomIndex(0, vNovice.size());
	int32 RandNum = randomIndex(RandomGenerator);
	const FString RandomHiddenWord = vNovice.at(RandNum);
	MyHiddenWord = RandomHiddenWord;
	}

	else if (NoviceFile.fail())
	{
	std::cerr << "\n There was an error opening the file. Please try again or select another difficulty. If continuously failing, please reload game entirely. \n";
	exit(1);
	}*/
	return;
}

void const FBullCow::NormalIsogram()
{
	std::vector<FString> vNormal =
	{
		"hapily", "sad", "smile"

	};
	std::default_random_engine RandomGenerator(std::time(NULL));
	std::uniform_int_distribution<int32> randomIndex(0, vNormal.size());
	int32 RandNum = randomIndex(RandomGenerator);
	const FString RandomHiddenWord = vNormal.at(RandNum);
	MyHiddenWord = RandomHiddenWord;

	/*std::ifstream NormalFile("NormalIsograms.txt2");
		if (NormalFile)
		{
			FString line;
			std::vector<FString>vNormal(0);
			while (std::getline(NormalFile, line))
			{
				if (NormalFile)
				{
					vNormal.push_back(line);
				}
			}

			std::uniform_int_distribution<int32> randomIndex(0, vNormal.size());
			int32 RandNum = randomIndex(RandomGenerator);
			const FString RandomHiddenWord = vNormal.at(RandNum);
			MyHiddenWord = RandomHiddenWord;
		}

		else if (NormalFile.fail())
		{
			std::cerr << "\n There was an error opening the file. Please try again or select another difficulty. If continuously failing, please reload game entirely. \n";
			exit(1);
		}*/
	return;
}

void const FBullCow::NeverIsogram()
{
	std::vector<FString> vNever =
	{
		"hungry", "stufing", "fudge"

	};
	std::default_random_engine RandomGenerator(std::time(NULL));
	std::uniform_int_distribution<int32> randomIndex(0, vNever.size());
	int32 RandNum = randomIndex(RandomGenerator);
	const FString RandomHiddenWord = vNever.at(RandNum);
	MyHiddenWord = RandomHiddenWord;

	/*std::ifstream NeverFile("NeverIsograms2.txt");
	if (NeverFile)
	{
	FString line;
	std::vector<FString>vNever(0);
	while (std::getline(NeverFile, line))
	{
	if (NeverFile)
	{
	vNever.push_back(line);
	}
	}

	std::uniform_int_distribution<int32> randomIndex(0, vNever.size());
	int32 RandNum = randomIndex(RandomGenerator);
	const FString RandomHiddenWord = vNever.at(RandNum);
	MyHiddenWord = RandomHiddenWord;
	}

	else if (NeverFile.fail())
	{
	std::cerr << "\n There was an error opening the file. Please try again or select another difficulty. If continuously failing, please reload game entirely. \n";
	exit(1);
	}*/
	return;
}

//checks guess for validity before comparing to hidden word
EGuessStatus FBullCow::CheckGuessValidity(FString Guess)
{
	/*//Activating lines below will prioritze EGuessStatus::Incorrect_length  // keep bottom Incorrect_length regardless of this implementation
	if (Guess.length() != MyHiddenWord.length())
	{ return EGuessStatus::Incorrect_length; }*/

	//checks to ensure it is an isogram
	for (int32 GuessCharacter = 0; GuessCharacter < Guess.length(); GuessCharacter++)
	{
		for (int32 UpcomingCharacters = GuessCharacter + 1; UpcomingCharacters < Guess.length(); UpcomingCharacters++)
		{
			if (Guess[GuessCharacter] == Guess[UpcomingCharacters])
			{
				return EGuessStatus::Not_an_isogram;
			}
		}
	}

	//Checks to ensure proper capitalization
	for (int32 GuessUpper = 0; GuessUpper < Guess.length(); GuessUpper++)
	{
		if (isupper(Guess[GuessUpper]))
		{
			return EGuessStatus::Incorrect_capitalization;
		}
	}

	//Upon completing isogram & capitalization test, it's accepted if the length meets requirements 
	int32 const LengthException = 7;
	if (MyHiddenWord.length() < LengthException && Guess.length() != MyHiddenWord.length())
	{
		return EGuessStatus::Incorrect_length;
	}
	else
	{
		return EGuessStatus::Valid_entry;
	}
}

const bool FBullCow::getTwoButton(FString TwoButtonCheck) const
{
	for (int32 i = 0; i < TwoButtonCheck.length(); i++)
	{
		TwoButtonCheck[i] = tolower(TwoButtonCheck[i]);
	}

	if (TwoButtonCheck.substr(0, 3) == "two" || TwoButtonCheck == "2")
	{
		return true;
	}
	else return false;
}

const bool FBullCow::getHintButton(FString HintButtonCheck) const
{
	for (int32 i = 0; i < HintButtonCheck.length(); i++)
	{
		HintButtonCheck[i] = tolower(HintButtonCheck[i]);
	}

	if (HintButtonCheck == "off")
	{
		return false;
	}
	else return true;
}

//Compares a valid_entry Guess to hidden word to provide bull/cow hints & totals
FBullCowCount FBullCow::SubmitGuess(FString Guess, FString HintButton, FString BonusButton)
{
	//Instantiation for enumeration class
	FBullCowCount BullCowCount;

	//Collects letters of bulls 
	std::vector<char>vBullHint(0);
	//Collects letters of cows
	std::vector<char>vCowHint(0);

	//compare Guess to hidden word
	for (int32 GuessCharacter = 0; GuessCharacter < Guess.length(); GuessCharacter++)
	{
		for (int32 MHWCharacter = 0; MHWCharacter < Guess.length(); MHWCharacter++)  //take note that this compares Hidden word to Guess length as opposed to Hidden word length
		{
			if (Guess[GuessCharacter] == MyHiddenWord[MHWCharacter])
			{
				// add bulls (if they are in the same place)						
				if (GuessCharacter == MHWCharacter)

				{
					//adds bull hint				
					char vBGC = Guess[GuessCharacter];
					vBullHint.push_back(vBGC);

					//adds bull count
					BullCowCount.BullsNumber++;
				}
				else
				{
					//adds cow hint
					char vBGC = Guess[GuessCharacter];
					vCowHint.push_back(vBGC);

					//adds cow count			
					BullCowCount.CowsNumber++;
				}
			}
		}
	}

	std::cout << std::endl << Guess << " has " << BullCowCount.BullsNumber << " Bull(s) and " << BullCowCount.CowsNumber << " Cow(s).\n";

	//Does not provide a hint if all bulls are received or HintButton is turned off by user
	if (BullCowCount.BullsNumber == MyHiddenWord.length() || FBullCow::getHintButton(HintButton) == false)
	{
		return BullCowCount;
	}

	//Provides hints  //There is a commented alternatiive BonusButton in this loop that would double the bull/cow hints upon turining on bonusButton
	else if (FBullCow::getHintButton(HintButton) == true)
	{
		//Provides a hint if 0 < GuessBulls < HiddenWord.length && hint_button is turned on
		if (!vBullHint.empty())
		{
			int32 randomBullIndex = std::rand() % vBullHint.size();
			std::cout << "Bull hint: " << vBullHint.at(randomBullIndex);

			//adds a space if there are no cows for game aesthetics	
			if (vCowHint.empty()) { std::cout << std::endl; }

			/*if (FBullCow::getBonusButton(BonusButton) == true && vBullHint.size() > 1)
			{
				int32 randomBullIndexTwo = std::rand() % vBullHint.size();
				if (randomBullIndexTwo == randomBullIndex) { int32 randomBullIndexTwo = std::rand() % vBullHint.size(); }
				std::cout << "Bonus bull hint: " << vBullHint.at(randomBullIndex) << std::endl;
			}*/
		}

		//Provides a hint if there are any cows && hint_button is turned on
		if (!vCowHint.empty())
		{
			int32 randomCowIndex = std::rand() % vCowHint.size();
			std::cout << " Cow hint: " << vCowHint.at(randomCowIndex) << std::endl;

			/*if (FBullCow::getBonusButton(BonusButton) == true && vCowHint.size() > 1)
			{
				int32 randomCowIndexTwo = std::rand() % vCowHint.size();
				if (randomCowIndexTwo == randomCowIndex ) { int32 randomBullIndexTwo = std::rand() % vBullHint.size(); }
				std::cout << "Bonus cow hint: " << vCowHint.at(randomCowIndexTwo) << std::endl;
			}*/
		}
		return BullCowCount;
	}
}


