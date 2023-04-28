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
	//cout << vy << endl;
	if ((posObject.y + vy) > 892) {
		//cout << posObject.y <<vy << endl;

		return 1;
	}

	else if ((((posObject.y + vy) < FLOOR2Y - MARIO_HEIGHT + MARGIN) && ((posObject.y + vy) >= (FLOOR2Y - MARIO_HEIGHT))) && !(((posObject.x) < (1140 - heading * 10 - !heading * 36)) && ((posObject.x) > (780 + heading * 70 + ~heading * 10))) && (vy >= 0)) {
		return 1;
	}

	else if ((((posObject.y + vy) < FLOOR3Y - MARIO_HEIGHT + MARGIN) && ((posObject.y + vy) >= (FLOOR3Y - MARIO_HEIGHT))) && !(((posObject.x) < (1620 - heading * 10 - !heading * 36)) && ((posObject.x) > (300 + heading * 70 + ~heading * 10))) && (vy >= 0)) {
		return 1;
	}

	else if ((((posObject.y + vy) < FLOOR4Y - MARIO_HEIGHT + MARGIN) && ((posObject.y + vy) >= (FLOOR4Y - MARIO_HEIGHT))) && (((posObject.x) > (510 - heading * 10 - !heading * 36)) && ((posObject.x) < (1410 + heading * 70 + ~heading * 10))) && (vy >= 0)) {
		return 1;
	}

	else if ((((posObject.y + vy) < FLOOR5Y - MARIO_HEIGHT + MARGIN) && ((posObject.y + vy) >= (FLOOR5Y - MARIO_HEIGHT))) && !(((posObject.x) < (1200 - heading * 10 - !heading * 36)) && ((posObject.x) > (720 + heading * 70 + ~heading * 10))) && (vy >= 0)) {
		return 1;
	}
	return 0;
}