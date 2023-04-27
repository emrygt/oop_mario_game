#include "Object.h"

void Object::setPosition(Vector2f pos)
{
	this->pos = pos;
	sprite.setPosition(pos);
}

void Object::move(void) {

}

void Object::fall(void) {

}

void Object::jump(bool down) {

}