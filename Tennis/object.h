#include "Common.h"

class Object
{
public:
	Texture textures[8];
	Sprite sprite;
	Vector2f pos;
	void setPosition(Vector2f);
	int state, isJump, isFall;



};