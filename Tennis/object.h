#pragma once
#include "Common.h"

class Object {
	Object* object;

	Vector2f pos;

public:
	Object();

	Sprite sprite;
	void setPosition(Vector2f);
};