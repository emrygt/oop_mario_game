#pragma once
#include "Turtle.h"

Turtle::Turtle() {
	char path[64];
	for (int i = 1; i < 6; i++)
	{
		sprintf_s(path, "../assets/turtle%d.png", i);	// loading the textures
		textures[i - 1].loadFromFile(path);
	}

	//set initial texture
	state = 4;
	sprite.setTexture(textures[state]);
}

bool Turtle::isWallHit() {
	Vector2f v = this->getposition();
	if (v.x <= TURTLE_WIDTH && state < 4) {		// if turtle's x position is smaller than its width and is looking left he has hit the wall
		return true;
	}
	if (v.x >= WINDOW_WIDTH - TURTLE_WIDTH - 5 && state >= 4) {		// if turtle's x position is bigger than window width minus turtle width and is looking right he has hit the wall
		return true;
	}
	return false;
}

bool Turtle::isPipeHit() {		// when turtle enters into a pipe
	Vector2f v = this->getposition();
	if (v.x <= TURTLE_WIDTH + PIPE_WIDTH && v.y >= FLOOR2Y) {
		return true;
	}
	if (v.x >= WINDOW_WIDTH - TURTLE_WIDTH - 5 - PIPE_WIDTH && v.y >= FLOOR2Y) {
		return true;
	}
	return false;
}

void Turtle::move(void) {	// implemented after drawing the state diagram
	int speed = 7;
	int wait = 10;
	if (isJump) {	// control turtle's falling down speed
		sprite.move(sf::Vector2f(state >= 4 ? speed : -speed, vy));
		vy += 3;
		isJump = 0;
		return;
	}
	if (isPipeHit()) {		// if a turtle enters into a pipe, she will pop out from another pipe
		Vector2f posTurtle = this->getposition();
		if (posTurtle.x < WINDOW_WIDTH / 2) {
			sprite.setPosition((PIPES_WIDTH - 20), (FLOOR5Y - TURTLE_HEIGHT - 50));
			state = 4;
		}
		else {
			sprite.setPosition((WINDOW_WIDTH - PIPES_WIDTH + 40), (FLOOR5Y - TURTLE_HEIGHT - 50));
			state = 1;
		}
	}
	switch (state) {	// states
	case 1:		// moving left image 1
		sprite.setTexture(textures[0]);
		sprite.setScale(-1, 1);
		sprite.move(sf::Vector2f(-speed, 0));
		wallHit = isWallHit();
		if (!wallHit) {			
			state = 2;
		}
		else {
			wallHit = false;
			sprite.move(sf::Vector2f(-TURTLE_WIDTH, 0));
			state = 4;
			footstate = false;
		}
		break;

	case 2:		// moving left image 2
		sprite.setTexture(textures[1]);
		sprite.setScale(-1, 1);
		sf::sleep(sf::milliseconds(wait));
		sprite.move(sf::Vector2f(-speed, 0));
		wallHit = isWallHit();
		if (!wallHit) {			
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
			wallHit = false;
			sprite.move(sf::Vector2f(-TURTLE_WIDTH, 0));
			state = 4;
			footstate = false;
		}

		break;
	case 3:		// moving left image 3
		sprite.setTexture(textures[2]);
		sprite.setScale(-1, 1);
		sf::sleep(sf::milliseconds(wait));
		sprite.move(sf::Vector2f(-speed, 0));
		wallHit = isWallHit();
		if (!wallHit) {			
			state = 2;
		}
		else {
			wallHit = false;
			sprite.move(sf::Vector2f(-TURTLE_WIDTH, 0));
			state = 4;
			footstate = false;
		}
		break;
	case 4:		// moving right image 1
		sprite.setTexture(textures[0]);
		sprite.setScale(1, 1);
		sf::sleep(sf::milliseconds(wait));		
		sprite.move(sf::Vector2f(speed, 0));
		wallHit = isWallHit();
		if (!wallHit)
		{			
			state = 5;
		}
		else
		{
			wallHit = false;
			sprite.move(sf::Vector2f(TURTLE_WIDTH, 0));
			state = 1;
			footstate = false;
		}
		break;
	case 5:		// moving right image 2
		sprite.setTexture(textures[1]);
		sprite.setScale(1, 1);
		sf::sleep(sf::milliseconds(wait));
		sprite.move(sf::Vector2f(speed, 0));
		wallHit = isWallHit();
		if (!wallHit) {			
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
			wallHit = false;
			sprite.move(sf::Vector2f(TURTLE_WIDTH, 0));
			state = 1;
			footstate = false;
		}
		break;
	case 6:		// moving right image 3
		sprite.setTexture(textures[2]);
		sprite.setScale(1, 1);
		sf::sleep(sf::milliseconds(wait));
		sprite.move(sf::Vector2f(speed, 0));
		wallHit = isWallHit();
		if (!wallHit) {			
			state = 5;
		}
		else {
			wallHit = false;
			sprite.move(sf::Vector2f(TURTLE_WIDTH, 0));
			state = 1;
			footstate = false;
		}
		break;
	case 7:		// death
		sf::sleep(sf::milliseconds(wait));
		sprite.setTexture(textures[4]);
		sprite.setScale(1, 1);
		fall();		
		break;
	}	
}

void Turtle::fall(void)
{
	sprite.move(sf::Vector2f(0, 10));	// Turtle falls down from the screen when death happens
}

void Turtle::jump(void)
{
	Vector2f posTurtle = sprite.getPosition();
	if (onFloor()) {	// ensure turtle lands properly
		if (posTurtle.y > FLOOR2Y)		// setting position according to current position
			sprite.setPosition((posTurtle.x + vx), (FLOOR1Y - TURTLE_HEIGHT));
		else if (posTurtle.y > FLOOR3Y)
			sprite.setPosition((posTurtle.x + vx), (FLOOR2Y - TURTLE_HEIGHT));
		else if (posTurtle.y > FLOOR4Y)
			sprite.setPosition((posTurtle.x + vx), (FLOOR3Y - TURTLE_HEIGHT));
		else if (posTurtle.y > FLOOR5Y)
			sprite.setPosition((posTurtle.x + vx), (FLOOR4Y - TURTLE_HEIGHT));
		else
			sprite.setPosition((posTurtle.x + vx), (FLOOR5Y - TURTLE_HEIGHT));
		vy = 0;		// stop vertical movement
		isJump = 0;	// disable flag
	}	
}
