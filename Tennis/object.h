#pragma once
#include "Common.h"

class Object
{
public:
	float vx{};
	float vy{};

	Texture textures[8];
	Sprite sprite;
	Vector2f pos;
	int state, isJump, isFall;
	int heading;

	bool footstate{};

	enum WalkDirection {
		Left,
		Right,
		Null
	};

public:
	Object();
	Vector2f getposition();
	void setPosition(Vector2f);
	void draw(RenderWindow*);
	void move(void);
	void fall(void);
	void jump(bool);

	bool onFloor();
	bool wallHit;
	bool isWallHit(void);
	bool isPipeHit(void);



};