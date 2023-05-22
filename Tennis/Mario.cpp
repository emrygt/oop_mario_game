#pragma once
#include "Mario.h"


Mario::Mario ()
{
	char path[64];
	for (int i = 1; i < 8; i++) 
	{
		sprintf_s(path, "../assets/mario%d.png", i); //loading the textures
		textures[i - 1].loadFromFile(path);
	}

	state = 1;
	int footstate;
	sprite.setTexture(textures[state]); //setting the sprite according to the state
}

bool Mario::isWallHit() {
	Vector2f v = this->getposition();
	if (v.x <= 0 && state < 7) { //if mario's x position is smaller than 0 and mario is looking left he has hit the wall
		return true;
	}
	if (v.x >= WINDOW_WIDTH - 7 && state > 7) {//if mario's x position is biggerer than window width and mario is looking right he has hit the wall
		return true;
	}
	return false;
}

bool Mario::isPipeHit() {
	Vector2f v = this->getposition();
	if (v.x <= PIPE_WIDTH - 10 && v.y >= FLOOR2Y) { // mario's hitting the pipe conditions
		return true;
	}
	if (v.x <= PIPES_WIDTH - 10 && v.y < FLOOR5Y) {
		return true;
	}
	if (v.x >= WINDOW_WIDTH - PIPE_WIDTH + 10 && v.y >= FLOOR2Y) {
		return true;
	}
	if (v.x >= WINDOW_WIDTH - PIPES_WIDTH + 10 && v.y < FLOOR5Y) {
		return true;
	}
	return false;
}

void Mario::jump(bool down)
{
	
	Vector2f posMario=sprite.getPosition();
	if (down == 0)
	{	
		if (onFloor()) {	//this function makes sure that mario lands properly
			
			if(posMario.y>FLOOR2Y)	//if mario is under floor two then land mario specified coordinates
				sprite.setPosition((posMario.x + vx), (FLOOR1Y - MARIO_HEIGHT));
			else if (posMario.y > FLOOR3Y)  //if mario is on the third floor then land mario specified coordinates
				sprite.setPosition((posMario.x + vx), (FLOOR2Y - MARIO_HEIGHT));
			else if (posMario.y > FLOOR4Y)
				sprite.setPosition((posMario.x + vx), (FLOOR3Y - MARIO_HEIGHT));
			else if (posMario.y > FLOOR5Y)
				sprite.setPosition((posMario.x + vx), (FLOOR4Y - MARIO_HEIGHT));
			else
				sprite.setPosition((posMario.x + vx), (FLOOR5Y - MARIO_HEIGHT));
			vx = 0; //stop mario
			vy = 0;
			isJump = 0;	//disable jump flag
			if (heading == 0) //set state back to walking states according to the heading
				state = 1;
			if (heading == 1) 
				state = 8;
		}

		if (headBump()) { //if mario bumps his head to ceiling, make zero its vertical speed
			vy = 0;
		}
	
		else 
		{ 
			sprite.move(Vector2f(vx * 0.9, vy));// if mario is not on floor and headBump is zero, continue jumping
			vy += 1; // gravity
		}
	}

	if (down == 1)
	{
		isJump = 1; // if onFloor is 0 and mario is not jumping, fall to down floor with vy=0
	}
}

bool Mario::headBump() { //checks if mario hits his head to a ceiling while jumping

	Vector2f posMario = sprite.getPosition();

	if ((((posMario.y + vy) < FLOOR2Y + BOXSIZE) && ((posMario.y + vy) > FLOOR2Y + BOXSIZE - MARGIN)) && !(((posMario.x + vx) < (WINDOW_WIDTH - FLOOR2BOX * BOXSIZE - MARIO_WIDTH + heading * MARIO_WIDTH)) && (posMario.x + vx) > (FLOOR2BOX * BOXSIZE + heading * MARIO_WIDTH)) && (vy < 0)) 
		return 1;
	else if ((((posMario.y + vy) < FLOOR3Y + BOXSIZE) && ((posMario.y + vy) > FLOOR3Y + BOXSIZE - MARGIN)) && !(((posMario.x + vx) < (WINDOW_WIDTH - FLOOR3BOX * BOXSIZE - MARIO_WIDTH + heading * MARIO_WIDTH )) && (posMario.x + vx) > (FLOOR3BOX * BOXSIZE + heading * MARIO_WIDTH)) && (vy < 0)) 
		return 1;
	else if ((((posMario.y + vy) < FLOOR4Y + BOXSIZE) && ((posMario.y + vy) > FLOOR4Y + BOXSIZE - MARGIN)) && (((posMario.x + vx) > ((WINDOW_WIDTH - FLOOR4BOX * BOXSIZE) / 2 - MARIO_WIDTH + heading * MARIO_WIDTH)) && (posMario.x + vx) < (((WINDOW_WIDTH + FLOOR4BOX * BOXSIZE) / 2) + heading * MARIO_WIDTH)) && (vy < 0))
		return 1;
	else if ((((posMario.y + vy) < FLOOR5Y + BOXSIZE) && ((posMario.y + vy) > FLOOR5Y + BOXSIZE - MARGIN)) && !(((posMario.x + vx) < (WINDOW_WIDTH - FLOOR5BOX * BOXSIZE - MARIO_WIDTH + heading * MARIO_WIDTH )) && (posMario.x + vx) > (FLOOR5BOX * BOXSIZE + heading * MARIO_WIDTH)) && (vy < 0)) 
		return 1;
	else if ((posMario.y + vy) < 0)
		return 1;
	return 0;

}


void Mario::fall(void)
{	
	sprite.move(Vector2f(0, 10));	//Mario falls down from the screen if he dies
}

void Mario::move(WalkDirection dir)	//state diagram
{

	int speed;
	if (isWallHit() || isPipeHit()) { // if mario hits somewhere stop mario
		speed = 0;
	}
	else {
		speed = 7; // mario's default speed
	}
	switch (state) {
	case 1: //stand still looking left
		
		if (dir == WalkDirection::Right) //if right button is pressed, stand still looking right
		{
			sprite.move(sf::Vector2f(speed + MARIO_WIDTH,0));
			state = 8;

			vx = 0;
		}
		else if (dir == WalkDirection::Left) //if left button is pressed, start walking left
		{
			sprite.move(sf::Vector2f(-speed,0));
			state = 2;
		}
		else if (isJump)	//if jump is invoked go to jump looking left state
		{
			state = 6;
		}
		break;

	case 2://mario walking left 
		if (dir == WalkDirection::Left)// walk left
		{
			sprite.move(sf::Vector2f(-speed, 0));
			state = 3;
		}
		else if (isJump) //jump
		{
			state = 6;
			vx = -speed;
		}
		else //if mario is not walking or jumping, go back to standing still
		{
			state = 1;
		}
		
		break;
	case 3://mario walking left
		if (dir == WalkDirection::Left && footstate == 0)//go to state 4 according to footstate
		{
			sprite.move(sf::Vector2f(-speed, 0));
			state = 4;
			footstate = 1;
		}
		else if (dir == WalkDirection::Left && footstate == 1)//go to state 2 according to footstate
		{
			sprite.move(sf::Vector2f(-speed, 0));
			state = 2;
			footstate = 0;
		}
		else if (isJump) //jump
		{
			state = 6;
			vx = -speed;
		}
		else //if mario is not walking or jumping, go back to standing still
		{
			state = 1;
		}
		break;
	case 4:
		if (dir == WalkDirection::Left) //walk left
		{
			sprite.move(sf::Vector2f(-speed, 0));
			state = 3;
		}
		else if (isJump) //jump
		{
			state = 6;
			vx = -speed;
		}
		else //if mario is not walking or jumping, go back to standing still
		{
			state = 1;
		}
		break;
	case 5: // reserved for bonus 
		break;
	case 6: //jump looking left state
		jump(0);
		//state = 1;
		break;
	case 7: //dead state
		fall();
		if (sprite.getPosition().y > WINDOW_HEIGHT) { //if mario is gone from the screen, respawn him
			state = 1;
			sprite.setPosition(((WINDOW_WIDTH - MARIO_WIDTH) / 2), (FLOOR1Y - MARIO_HEIGHT));
		}		
		break;
	case 8: //mario standing still looking right

		if (dir == WalkDirection::Left) // if left is pressed mario stands still looking right
		{
			sprite.move(sf::Vector2f(-speed - MARIO_WIDTH, 0));
			state = 1;
			vx=0;
		}
		else if (dir == WalkDirection::Right) //walk right
		{
			sprite.move(sf::Vector2f(speed, 0));
			state = 9;
		}
		else if (isJump) //jump
		{
			state = 13;
		}
		break;

	case 9:
		if (dir == WalkDirection::Right) //walk right
		{
			sprite.move(sf::Vector2f(speed, 0));
			state = 10;
		}
		else if (isJump) //jump
		{
			state = 13;
			vx = speed;
		}
		else  //if mario is not walking or jumping, go back to standing still
		{
			state = 8;
		}
		break;
	case 10:
		if (dir == WalkDirection::Right && footstate == 0) //go to state 11 according to footstate
		{
			sprite.move(sf::Vector2f(speed, 0));
			state = 11;
			footstate = 1;
		}
		else if (dir == WalkDirection::Right && footstate == 1) //go to state 9 according to footstate
		{
			sprite.move(sf::Vector2f(speed, 0));
			state = 9;
			footstate = 0;
		}
		else if (isJump) //jump
		{
			state = 13;
			vx = speed;
		}
		else //if mario is not walking or jumping, go back to standing still
		{
			state = 8;
		}
		break;
	case 11:
		if (dir == WalkDirection::Right) //walk right
		{
			sprite.move(sf::Vector2f(speed, 0));
			state = 10;
		}
		else if (isJump) //jump
		{
			state = 13;
			vx = speed;
		}
		else //if mario is not walking or jumping, go back to standing still
		{
			state = 8;
		}
		break;
	case 12:
		break;// reserved for bonus
	case 13:
		jump(0); //jump
		break;

	}
	
	
	if (state > 7){ //if state is greater than 7 mario is looking right
		heading = 1;
		sprite.setTexture(textures[state-8]); //assign sprites according to the states
		sprite.setScale(-1, 1); //mirror the original images
	}
	if (state <= 7) {//if state is lower than 7 mario is looking left 
		heading = 0;
		sprite.setTexture(textures[state - 1]);//assign sprites according to the states
		sprite.setScale(1, 1);
	}
}