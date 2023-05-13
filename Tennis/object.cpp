#pragma once
#include "Object.h"


Object::Object() {

}

Vector2f Object::getposition()
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

	if ((posObject.y + vy) > 892) {
		return 1;
	}
	else if ((((posObject.y + vy) < FLOOR2Y - MARIO_HEIGHT + MARGIN) && ((posObject.y + vy) >= (FLOOR2Y - MARIO_HEIGHT))) && !(((posObject.x) < (WINDOW_WIDTH-FLOOR2BOX*BOXSIZE - heading * 10 - !heading * 36)) && ((posObject.x) > (FLOOR2BOX*BOXSIZE + heading * 70 + ~heading * 10))) && (vy >= 0)) {
		return 1;
	}
	else if ((((posObject.y + vy) < FLOOR3Y - MARIO_HEIGHT + MARGIN) && ((posObject.y + vy) >= (FLOOR3Y - MARIO_HEIGHT))) && !(((posObject.x) < (WINDOW_WIDTH - FLOOR3BOX * BOXSIZE - heading * 10 - !heading * 36)) && ((posObject.x) > (FLOOR3BOX * BOXSIZE + heading * 70 + ~heading * 10))) && (vy >= 0)) {
		return 1;
	}
	else if ((((posObject.y + vy) < FLOOR4Y - MARIO_HEIGHT + MARGIN) && ((posObject.y + vy) >= (FLOOR4Y - MARIO_HEIGHT))) && (((posObject.x) > ((WINDOW_WIDTH - FLOOR4BOX * BOXSIZE)/2 - heading * 10 - !heading * 36) && ((posObject.x) < (WINDOW_WIDTH + FLOOR4BOX * BOXSIZE) / 2 + ~heading * 10))) && (vy >= 0)) {
		return 1;
	}
	else if ((((posObject.y + vy) < FLOOR5Y - MARIO_HEIGHT + MARGIN) && ((posObject.y + vy) >= (FLOOR5Y - MARIO_HEIGHT))) && !(((posObject.x) < (WINDOW_WIDTH - FLOOR5BOX * BOXSIZE - heading * 10 - !heading * 36)) && ((posObject.x) > (FLOOR5BOX * BOXSIZE + heading * 70 + ~heading * 10))) && (vy >= 0)) {
		return 1;
	}
	return 0;
}

bool Object::isWallHit(void)
{
	return false;
}

bool Object::isPipeHit(void) {
	return false;
}
