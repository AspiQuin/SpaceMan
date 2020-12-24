#include "TextObject.h"

TextObject::TextObject() {
	password = "default";
	PrintWordAndCheckWin();
	alphabet = PrintAvailableLetters();

}

TextObject::TextObject(string pass) {
	password = pass;
	PrintWordAndCheckWin();
	alphabet = PrintAvailableLetters();
}

TextObject::~TextObject() {

}

//Return the number of errors in the guesses list
int TextObject::TriesLeft()
{
	int error = 0;
	for (unsigned int i = 0; i < guesses.length(); i++)
	{
		if (password.find(guesses[i]) == string::npos)
			error++;
	}

	return error;
}


//Set blank spaces in the guessed password
bool TextObject::PrintWordAndCheckWin()
{
	bool won = true;
	string s = "";
	for (unsigned int i = 0; i < password.length(); i++)
	{
		if (guesses.find(password[i]) == string::npos)
		{
			won = false;
			s += "_ ";
		}
		else
		{
			s += password[i];
			s += " ";
		}
	}
	wordToGuess = s;


	return won;
}

//Print letters in a range of characters
string PrintLetters(string input, char from, char to)
{
	string s;
	for (char i = from; i <= to; i++)
	{
		if (input.find(i) == string::npos)
		{
			s += i;
			s += " ";
		}
		else
			s += "  ";
	}
	return s;
}

//Print Available letters from guesses
string TextObject::PrintAvailableLetters()
{

	alphabet = PrintLetters(guesses, 'A', 'M');
	alphabet += PrintLetters(guesses, 'N', 'Z');
	return alphabet;
}