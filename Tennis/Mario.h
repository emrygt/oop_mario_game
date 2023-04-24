#pragma once
#include "Common.h"

class Mario {
	int state;
	int footstate;
	Vector2f pos;
	Texture textures[14];
	//Texture texture;
	Sprite sprite;
	RenderWindow* window;
	Mario* mario;
	int speed;

public:
	enum WalkDirection {
		Up,
		Down,
		Left,
		Right
	};
	Mario();
	void walk(WalkDirection dir);
	void setPosition(Vector2f);
	void draw(RenderWindow*);
};