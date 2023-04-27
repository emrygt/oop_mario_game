#pragma once
#include "Common.h"
#include "Object.h"

class Mario : public Object {
	int footstate;
	Mario* mario;

public:
	float vx; //Horizontal speed 
	float vy;
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