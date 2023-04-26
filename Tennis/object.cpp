#include "Object.h"

Object::Object()
{
}

void Object::setPosition(Vector2f pos)
{
	this->pos = pos;
	sprite.setPosition(pos);
}