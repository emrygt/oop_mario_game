#include "Turtle.h"

//turtle ne zaman ve nasil oluyor onu belli etmedim

Turtle::Turtle() {
	char path[64];
	for (int i = 1; i < 6; i++)
	{
		sprintf_s(path, "../assets/turtle%d.png", i);
		textures[i - 1].loadFromFile(path);
	}

	//set initial texture
	state = 1;
	sprite.setTexture(textures[state]);
}

void Turtle::move(void)
{
	int speed = 7;
	int wait = 60;
	switch (state) {
	case 1:
		sprite.setTexture(textures[0]);
		sprite.setScale(-1, 1);
		if (!isWallHit) {
			sprite.move(sf::Vector2f(-speed, 0));
			state = 2;
			//vx = 0;
		}
		else {
			state = 4;
			footstate = false;
		}
		break;

	case 2:
		sprite.setTexture(textures[1]);
		sprite.setScale(-1, 1);
		sf::sleep(sf::milliseconds(wait));
		if (!isWallHit) {
			sprite.move(sf::Vector2f(-speed, 0));
			if (footstate) {
				state = 1;
				footstate = false;
			}
			else {
				state = 3;
				footstate = true;
			}
		}
		else {
			state = 4;
			footstate = false;
		}

		break;
	case 3:
		sprite.setTexture(textures[2]);
		sprite.setScale(-1, 1);
		sf::sleep(sf::milliseconds(wait));
		if (!isWallHit) {
			sprite.move(sf::Vector2f(-speed, 0));
			state = 2;
		}
		else {
			state = 4;
			footstate = false;
		}
		break;
	case 4:
		sprite.setTexture(textures[0]);
		sprite.setScale(1, 1);
		sf::sleep(sf::milliseconds(wait));
		if (!isWallHit)
		{
			sprite.move(sf::Vector2f(speed, 0));
			state = 5;
		}
		else
		{
			state = 1;
			footstate = false;
			//vx = -speed;
		}
		break;
	case 5:
		sprite.setTexture(textures[1]);
		sprite.setScale(1, 1);
		sf::sleep(sf::milliseconds(wait));
		if (!isWallHit) {
			sprite.move(sf::Vector2f(speed, 0));
			if (footstate) {
				state = 4;
				footstate = false;
			}
			else {
				state = 6;
				footstate = true;
			}
		}
		else {
			state = 1;
			footstate = false;
		}
		break;
	case 6:
		sprite.setTexture(textures[2]);
		sprite.setScale(1, 1);
		sf::sleep(sf::milliseconds(wait));
		if (!isWallHit) {
			sprite.move(sf::Vector2f(speed, 0));
			state = 5;
		}
		else {
			state = 1;
			footstate = false;
		}
		break;
	case 7:
		fall();
		sprite.setTexture(textures[4]);
		break;
	}	
}

void Turtle::fall(void)
{
	sprite.move(Vector2f(0, vy));
}

void Turtle::jump(bool down)
{
	Vector2f posTurtle = sprite.getPosition();
	if (!down)
	{
		if (onFloor()) {
			if (posTurtle.y > FLOOR2Y)
				sprite.setPosition((posTurtle.x + vx), (FLOOR1Y - TURTLE_HEIGHT));
			else if (posTurtle.y > FLOOR3Y)
				sprite.setPosition((posTurtle.x + vx), (FLOOR2Y - TURTLE_HEIGHT));
			else if (posTurtle.y > FLOOR4Y)
				sprite.setPosition((posTurtle.x + vx), (FLOOR3Y - TURTLE_HEIGHT));
			else if (posTurtle.y > FLOOR5Y)
				sprite.setPosition((posTurtle.x + vx), (FLOOR4Y - TURTLE_HEIGHT));
			else
				sprite.setPosition((posTurtle.x + vx), (FLOOR5Y - TURTLE_HEIGHT));
			vy = 0;
			isJump = 0;
		}		
	} else
		isJump = 1; // if onFloor is 0 and turtle is not jumping, fall to down floor with vy=0
}
