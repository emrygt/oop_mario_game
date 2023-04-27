#pragma once
#include "Common.h"
#include "Object.h"

class Mario : public Object {
	int j,k;
	int footstate;
	Texture textures[14];
	Mario* mario;

public:
	int speed;
	float vx; //Horizontal speed 
	float vy;
	int state,isJump,isFall;
	enum WalkDirection {
		Left,
		Right,
		Space
	};
	Mario();
	void walk(WalkDirection dir);
	void jump(bool);
	void fall(void);
	void draw(RenderWindow*);
};