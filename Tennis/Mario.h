#pragma once
#include "Common.h"
#include "Object.h"

class Mario : public Object {

public:
	//float vx{};
	//float vy{};
	int isHeadBump{};
	
	Mario();
	void move(WalkDirection dir);
	void jump(bool);
	void fall(void);
};