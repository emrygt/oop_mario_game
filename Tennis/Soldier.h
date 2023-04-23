#pragma once
#include "Common.h"

class Soldier {
	int state;
	int footstate;
	Vector2f pos;
	Texture textures[14];
	//Texture texture;
	Sprite sprite;
	RenderWindow* window;
	Soldier* soldier;
	int speed;

public:
	enum WalkDirection {
		Up,
		Down,
		Left,
		Right
	};
	Soldier();
	void walk(WalkDirection dir);
	void setPosition(Vector2f);
	void draw(RenderWindow*);
};