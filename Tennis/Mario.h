#pragma once
#include "Common.h"

class Mario {
	int state,j,k;
	int footstate;
	Vector2f pos;
	Texture textures[14];
	Mario* mario;
	int speed;

public:
	float vx; //Horizontal speed 
	float vy;
	Sprite sprite;
	int isJump;
	enum WalkDirection {
		Left,
		Right,
		Space
	};
	Mario();
	void walk(WalkDirection dir);
	//void setPosition(Vector2f);
	void jump(bool);
	void draw(RenderWindow*);
};