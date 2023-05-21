#pragma once
#include "Common.h"
#include "Object.h"

class Mario : public Object {

public:
	//float vx{};
	//float vy{};
	int isHeadBump{};
	Mario();
	void move(WalkDirection);
	void jump(bool);
	void fall(void);
	bool headBump();
	bool isWallHit();
	bool isPipeHit();
};