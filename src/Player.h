#pragma once
#include "ofImage.h"
#include "ofVec2f.h"

using namespace std;

class Player 
{
public:
	//Player display and control variables
	ofImage spaceman;
	ofVec2f spacePos;
	float spaceTarget;
	int screenWidth;


	Player();
	Player(string path, ofVec2f pos, int scrWid);

	~Player();

	void movePlayer();

	void reTargetPlayer();

	void deathPlayer();

	float lerp(float a, float b, float t);
};

