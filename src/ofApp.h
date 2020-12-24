/*
Author:  Quinlan Walker
Class: IMD3005 - Software Design For Multimedia
Description: Its a hangman game...(WIP)
*/
#pragma once

#include "ofMain.h"
#include "Constants.h"
//#include "graphics/ofImage.h"
#include "Player.h"
#include "TextObject.h"
#include<string>
#include<iostream>
#include <cctype>

using namespace std;

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		ofImage videoFrame;

		//Play state controllers
		int count;
		int tick;
		int itter;
		bool win;
		bool dead;
		int errors;
		int state;

		Player player;

		TextObject password;

		//Init night sky
		static const int STARS = 1000;
		ofImage bgImage;
		ofVec3f starPos[STARS];
		ofImage starySun;

		ofImage logo;
		ofImage rules;

		//Init file reading
		ofFile words;
		ofBuffer buff;

		//Init font variables
		ofTrueTypeFont myFont;
		ofTrueTypeFont exitFont;

		//load all UI text bounding box
		ofRectangle startRect;
		ofRectangle stringRect;
		ofRectangle alphabitRect;
		ofRectangle winRect;
		ofRectangle lossRect;
		ofRectangle exitRect;


		void keyPressed(int key);

		void createStars();

		//Load files
		string LoadRandomWord(string path);

		//simple lerp
		float lerp(float a, float b, float t);

		
};
