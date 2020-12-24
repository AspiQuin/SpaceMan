#include "ofApp.h"
//#include <iostream>
//#include <vector>
//#include <fstream>
//#include <string>
#include <time.h>
//using namespace std;


//--------------------------------------------------------------
void ofApp::setup(){
	//set the inital state of the program
	state = Constants::GAMESTATES::MENU;
	
	//load both types of fonts
	myFont.load("EricaOne-Regular.ttf", 52);//Licence: https://scripts.sil.org/cms/scripts/page.php?site_id=nrsi&id=OFL
	exitFont.load("EricaOne-Regular.ttf", 30);//Licence: https://scripts.sil.org/cms/scripts/page.php?site_id=nrsi&id=OFL

	//these bounding boxes help with centering dynamicly
	startRect = exitFont.getStringBoundingBox(Constants::START_DECLA, 0, 0);
	lossRect = myFont.getStringBoundingBox(Constants::LOSS_DECLA, 0, 0);
	winRect = myFont.getStringBoundingBox(Constants::WIN_DECLA, 0, 0);
	exitRect = exitFont.getStringBoundingBox(Constants::EXIT_DECLA, 0, 0);
	alphabitRect = myFont.getStringBoundingBox(password.PrintAvailableLetters(), 0, 0);
	

	//Init Player
	player = Player(Constants::PATH, ofVec2f(0, ofGetWindowHeight() / 2), ofGetWindowWidth());
	
	//Init Sun
	starySun.load("image/sun.PNG");
	starySun.setAnchorPercent(0.5, 0.5);

	//Init Asset Images
	logo.load("image/logo.png");
	rules.load("image/rules.png");

	//Init random Password
	password = TextObject(LoadRandomWord("words.txt"));

	//Init the star positions for the backgound
	for (int i = 0; i < STARS; i++) {
		
		starPos[i].x = ofRandomWidth();
		starPos[i].y = ofRandomHeight();
	}
	

	//set framerate
	ofSetFrameRate(30);
}

//--------------------------------------------------------------
void ofApp::update(){
	//Finite State Controller
	switch (state) {

	case(Constants::MENU):
		//UI Code
		//state = Constants::TUTORIAL;
		break;
	case(Constants::TUTORIAL):
		//Tutorial Image and Timer
		tick++;
		
		if(tick>210){
			state = Constants::GAME;
		}

		//state = Constants::GAME;
		break;
	case(Constants::GAME):
		password.PrintAvailableLetters();
		//
		win = password.PrintWordAndCheckWin();

		if (win)
			state = Constants::END;


		//player.movePlayer();
		
		switch (errors) {
		case(0):
			player.movePlayer();
			//spaceTarget += ofGetWindowWidth() / 7;
			break;
		case(1):
			player.movePlayer();
			//spaceTarget += ofGetWindowWidth() / 7;
			break;
		case(2):
			player.movePlayer();
			//spaceTarget += ofGetWindowWidth() / 7;
			break;
		case(3):
			player.movePlayer();

			//spaceTarget += ofGetWindowWidth() / 7;
			break;
		case(4):
			player.movePlayer();

			//spaceTarget += ofGetWindowWidth() / 7;
			break;
		case(5):
			player.movePlayer();

			//spaceTarget += ofGetWindowWidth() / 7;
			break;
		case(6):
			player.movePlayer();

			dead = true;
			state = Constants::END;
			
			break;
		default:
			break;
		}
		
		break;
	case(Constants::END):
		if (dead) {
			player.deathPlayer();
			state = Constants::END;
		}
		
		break;
	}
	
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofBackground(25);
	ofSetColor(255);
	
	ofFill();
	createStars();

	//Finite State Controller
	switch (state) {
	case(Constants::MENU):
		//draw UI
		logo.draw(ofGetWindowWidth() / 2 - logo.getWidth() / 2, ofGetWindowHeight() / 2 - 20);
		exitFont.drawString(Constants::START_DECLA, ofGetWindowWidth() / 2 - startRect.getWidth() / 2, ofGetWindowHeight() / 2 + 100);
		break;
	case(Constants::TUTORIAL):
		//Display Tutorial
		rules.draw(ofGetWindowWidth() / 2 - logo.getWidth() / 2 - 120, ofGetWindowHeight() / 2 - 230);
		break;
	case(Constants::GAME):
		//Draw game UI
		myFont.drawString(password.wordToGuess, ofGetWindowWidth() / 2 - stringRect.getWidth() / 2, 100);
		myFont.drawString(password.alphabet, ofGetWindowWidth()/2 - alphabitRect.getWidth()/2, ofGetWindowHeight() - 100);

	
		//ofSetColor(255, 165, 0);
		//ofDrawCircle(ofGetWindowWidth(), ofGetWindowHeight() / 2, ofGetWindowHeight() / 2 - 20);
		starySun.draw(ofVec2f(ofGetWindowWidth(), ofGetWindowHeight() / 2));
		//spaceman.update();
		ofSetColor(255);

		//draw player
		player.spaceman.draw(player.spacePos);
		break;
	case(Constants::END):
		//draw the sun
		starySun.draw(ofVec2f(ofGetWindowWidth(), ofGetWindowHeight() / 2));

		//maintain player consistency
		player.spaceman.draw(player.spacePos);

		//Display final state
		if (win)
		{
			myFont.drawString(Constants::WIN_DECLA, ofGetWindowWidth() / 2 - winRect.getWidth() / 2, ofGetWindowHeight() / 2);
		}
		if (dead) 
		{
			myFont.drawString(Constants::LOSS_DECLA, ofGetWindowWidth() / 2 - lossRect.getWidth() / 2, ofGetWindowHeight() / 2);
			exitFont.drawString(Constants::EXIT_DECLA, ofGetWindowWidth() / 2 - exitRect.getWidth() /2, ofGetWindowHeight() / 2+ 80);
		}

		break;
	}
	/*
	itter++;
	videoFrame.grabScreen(0, 0, ofGetWidth(), ofGetHeight());
	videoFrame.save("screenshot" + ofToString(itter) + ".png");
	*/
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	//Finite State Controller
	switch (state) {
	case(Constants::MENU):
		if (key = ' ') {
			//cout << "test";
			state = Constants::TUTORIAL;
		}
		break;
	case(Constants::TUTORIAL):

		break;
	case(Constants::GAME):
		//Convert char to cap because I like the Font
		key = toupper(key);

		//look for selected char in the password
		if (password.guesses.find(key) == string::npos)
			password.guesses += key;

		//when the player guesses wrong move the player closer to the sun
		if (errors != password.TriesLeft()) {
			errors = password.TriesLeft();

			player.reTargetPlayer();
		}
		break;
	case(Constants::END):
		//exit the game
		if (key) {
			ofExit();
		}
		break;
	}
	
}

//create starts with the positions created eariler
void ofApp::createStars() {
	for (int i = 0; i < STARS; i++) {
		ofDrawCircle(starPos[i], ofRandom(1, 3));
	}
}

//Load RandomWord from list
string ofApp::LoadRandomWord(string path)
{
	//local variables
	int charCount = 0;
	string word;
	vector <string> v;
	
	//attempt to read file
	buff = ofBufferFromFile(path, false);
	
	//if the file has been read
	if (buff.getData()!=nullptr)
	{
		//load lines into the string vector
		for (auto line : buff.getLines()) {
			word = line;
			v.push_back(word);
		}
		
		//get a random int in the index of v
		int randomLine = rand() % v.size();

		//load the password and close the files
		word = v.at(randomLine);
		words.close();
		buff.clear();
	}
	//normalize all chars to uppercase because I like the font better
	for (unsigned int i = 0; i < word.length(); i++)
	{
		//Ascii
		word[i] -= 32;
	}
	//Loads blank slots
	password.PrintWordAndCheckWin();
	//dynamic centering
	stringRect = myFont.getStringBoundingBox(word, 0, 0);
	return word;
}

//simple easing
float ofApp::lerp(float a, float b, float t) {
	return a + (b - a)*t;
}
