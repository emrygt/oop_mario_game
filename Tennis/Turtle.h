#pragma once
#include "Common.h"
#include "Object.h"

class Turtle : public Object {
public:
	Turtle();
	bool isWallHit;
	void move(void);
	void fall(void);
	void jump(bool);
};
