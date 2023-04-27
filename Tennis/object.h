#include "Common.h"

class Object
{
public:
	Texture textures[8];
	Sprite sprite;
	Vector2f pos;
	int state, isJump, isFall;

	void setPosition(Vector2f);
	void move(void);
	void fall(void);
	void jump(bool);



};