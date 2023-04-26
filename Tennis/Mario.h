#pragma once
#include "Common.h"

class Mario {
	int j,k;
	int footstate;
	Vector2f pos;
	Texture textures[14];
	Mario* mario;

public:
	int speed;
	float vx; //Horizontal speed 
	float vy;
	Sprite sprite;
	int state,isJump,isFall;
	enum WalkDirection {
		Left,
		Right,
		Space
	};
	Mario();
	void walk(WalkDirection dir);
	void setPosition(Vector2f);
	void jump(bool);
	void fall(void);
	void draw(RenderWindow*);
};