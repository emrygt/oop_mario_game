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

int Object::whichFloor() {
	Vector2f posObject = sprite.getPosition();
	cout << vy << endl;
	if ((posObject.y + vy) > 892) {
		cout << posObject.y <<vy << endl;

		return 1;
	}

	else if ((((posObject.y + vy) < 784) && ((posObject.y + vy) >= 662)) && !(((posObject.x + vx) < (1074 + heading * 56 - ~heading * 10)) && ((posObject.x + vx) > (780 + heading * 70 + ~heading * 10))) && (vy >= 0)) {
		return 2;
	}

	else if ((((posObject.y + vy) < 559) && ((posObject.y + vy) >= 437)) && !(((posObject.x + vx) < (1554 + heading * 56 - ~heading * 10)) && ((posObject.x + vx) > (300 + heading * 70 + ~heading * 10))) && (vy >= 0)) {
		return 3;
	}

	else if ((((posObject.y + vy) < 434) && ((posObject.y + vy) >= 312)) && (((posObject.x + vx) > (444 + heading * 56 - ~heading * 10)) && ((posObject.x + vx) < (1410 + heading * 70 + ~heading * 10))) && (vy >= 0)) {
		return 4;
	}

	else if ((((posObject.y + vy) < 234) && ((posObject.y + vy) >= 112)) && !(((posObject.x + vx) < (1134 + heading * 56 - ~heading * 10)) && ((posObject.x + vx) > (720 + heading * 70 + ~heading * 10))) && (vy >= 0)) {
		return 5;
	}
	return 0;
}