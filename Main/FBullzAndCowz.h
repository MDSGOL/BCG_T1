#include <string>
using FString = std::string;
using int32 = int;

// all values initialized to 0
struct FBullCowCount
{
	int32 BullsNumber = 0;
	int32 CowsNumber = 0;
};

enum class EGuessStatus
{
	Valid_entry,
	Not_an_isogram,
	Incorrect_capitalization,
	Incorrect_length
};

class FBullCow
{
public:
	//Reset changes the Hidden_Word
	void Reset(FString);

	void const NoviceIsogram();
	void const NormalIsogram();
	void const NeverIsogram();
	void const runBonusHint();
	//bool isGameWon(int32) const;
	FString getHiddenWord() const;
	int32 getHiddenWordLength() const;
	int32 getDifficulty(FString) const;
	const bool getTwoButton(FString) const;
	const bool getHintButton(FString) const;
	const bool getBonusButton(FString) const;
	EGuessStatus CheckGuessValidity(FString);
	FBullCowCount SubmitGuess(FString, FString, FString);
	//FBullCow(); // (unused) constructor

private:
	FString MyHiddenWord;
};

