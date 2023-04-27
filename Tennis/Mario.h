#pragma once
#include "Common.h"
#include "Object.h"

class Mario : public Object {

public:
	float vx; 
	float vy;
	enum WalkDirection {
		Left,
		Right,
		Space
	};
	Mario();
	void move(WalkDirection dir);
	void jump(bool);
	void fall(void);
	void draw(RenderWindow*);
};