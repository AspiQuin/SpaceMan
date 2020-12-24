#include "Player.h"

//Default Player Init
Player::Player() {
	spaceman.allocate(100, 100, OF_IMAGE_GRAYSCALE);
	
}

//Player Init
Player::Player(string path, ofVec2f pos, int scrWid) {
	screenWidth = scrWid;
	spaceman.load(path);
	spaceTarget = 100;
	spacePos = pos;
	spaceman.resize(spaceman.getWidth() / 24, spaceman.getHeight() / 24);
	spaceman.setAnchorPercent(0.5, 0.5);
}

//Deconstructor -may be unnessicary
Player::~Player() {
	
}

// move player with lerp
void Player::movePlayer() {
	spacePos.x = lerp(spacePos.x, spaceTarget, 0.05f);
}

//change the target for animation 
void Player::reTargetPlayer() {
	spaceTarget += screenWidth / 7;
}

//player death animation code
void Player::deathPlayer() {
	spaceman.resize(lerp(spaceman.getWidth(), 0, 0.05f), lerp(spaceman.getHeight(), 0, 0.05f));
	spacePos.x = lerp(spacePos.x, screenWidth, 0.05f);
}

//simple lerp
float Player::lerp(float a, float b, float t) {
	return a + (b - a)*t;
}