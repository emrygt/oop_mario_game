#pragma once

#include "Common.h"
#include "Mario.h"
#include "Turtle.h"


class Game
{
	int side;	// 10 for collusion from side, 20 for collusion from head
	Texture bgTextures[4];
	Sprite* bgSprites;
	Mario mario;
	Turtle turtle[5];
	int turtleNo = 0;
	int heart = 1;

public:
	Game();
	RenderWindow* window;
	void Background(void);
	bool checkCollusion(Turtle* t, Mario* m, int& side);
};