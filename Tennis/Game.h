#pragma once

#include "Common.h"
#include "Mario.h"
#include "Turtle.h"


class Game
{

	int side;	// 10 for collusion from side, 20 for collusion from head
	Texture bgTextures[4], hearttexture;
	Sprite* bgSprites, *heartsprite;
	Mario mario;
	Turtle turtle[TURTLE];
	int turtleNo = 0;
	int heart = HEART;
	int turtleLeft = TURTLE;

public:
	Font font;
	Text text_over,text_start,text_mario,text_win;
	Game();
	RenderWindow* window;
	void Background(void);
	bool checkCollusion(Turtle* t, Mario* m, int& side);
};