#pragma once
//#include "ofImage.h"
//#include "ofVec2f.h"
#include<string>

using namespace std;

class TextObject 
{
public:
	//Game strings
	string guesses;
	string wordToGuess;
	string password;
	string alphabet;

	TextObject();
	TextObject(string password);

	~TextObject();

	int TriesLeft();

	bool PrintWordAndCheckWin();

	string PrintAvailableLetters();
};

