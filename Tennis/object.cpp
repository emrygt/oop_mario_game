#include "Object.h"


Object::Object() {

}

Vector2f Object::getPosition()
{
	return{ sprite.getPosition() };
}

void Object::setPosition(Vector2f pos)
{
	this->pos = pos;
	sprite.setPosition(pos);
}

void Object::draw(RenderWindow* window)
{
	window->draw(sprite);
}

void Object::move(void) {

}

void Object::fall(void) {

}

void Object::jump(bool down) {

}

bool Object::onFloor() {
	Vector2f posObject = sprite.getPosition();
	if ((730 < posObject.y) && (posObject.y < 770)) {

		return 1;

	}
	return 0;
}