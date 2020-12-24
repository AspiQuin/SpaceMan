#pragma once
#include "ofApp.h"

namespace Constants {
	static const string WIN_DECLA = "Congratulations! You survived!";
	static const string LOSS_DECLA = "*sizzle*  GAME OVER";
	static const string EXIT_DECLA = "press ANY KEY to exit";
	static const string START_DECLA = "press SPACE to START";
	
	static const string PATH = "image/Asset 2.png";
	static const string LOGO = "image/logo.png";
	static const string RULES = "image/rules.png";

	enum GAMESTATES {
		MENU,
		TUTORIAL,
		GAME,
		END
	};
}