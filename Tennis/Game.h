#pragma once

#include "Common.h"
#include "Mario.h"
#include "Turtle.h"


class Game
{
	
	Texture bgTextures[4];
	Sprite* bgSprites;
	Mario mario;
	

public:
	Game();
	RenderWindow* window;
	void Background(void);
	
};