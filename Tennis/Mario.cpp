#include "Mario.h"


Mario::Mario ()
{
	char path[64];
	for (int i = 1; i < 8; i++) 
	{
		sprintf_s(path, "../assets/mario%d.png", i);
		textures[i - 1].loadFromFile(path);
	}

	state = 1;
	int footstate;
	sprite.setTexture(textures[state]);
}



void Mario::jump(bool down)
{
	
	Vector2f posMario=sprite.getPosition();
	if (down == 0)
	{	
		if (onFloor()) {
			
			if(posMario.y>FLOOR2Y)
				sprite.setPosition((posMario.x + vx), (FLOOR1Y - MARIO_HEIGHT));
			else if (posMario.y > FLOOR3Y)
				sprite.setPosition((posMario.x + vx), (FLOOR2Y - MARIO_HEIGHT));
			else if (posMario.y > FLOOR4Y)
				sprite.setPosition((posMario.x + vx), (FLOOR3Y - MARIO_HEIGHT));
			else if (posMario.y > FLOOR5Y)
				sprite.setPosition((posMario.x + vx), (FLOOR4Y - MARIO_HEIGHT));
			else
				sprite.setPosition((posMario.x + vx), (FLOOR5Y - MARIO_HEIGHT));
			vx = 0;
			vy = 0;
			isJump = 0;
			if (heading == 0) 
				state = 1;
			if (heading == 1) 
				state = 8;
		}

		if (headBump()) {
			vy = 0;
		}
	
		else 
		{ 
			sprite.move(Vector2f(vx/30, vy));// if onFloor and headBump is zero, continue jumping
			vy += 0.0015; // gravity
		}
	}

	if (down == 1)
	{
		isJump = 1; // if onFloor is 0 and mario is not jumping, fall to down floor with vy=0
	}
}

bool Mario::headBump() {

	Vector2f posMario = sprite.getPosition();

	if ((((posMario.y + vy) < FLOOR2Y + BOXSIZE) && ((posMario.y + vy) > FLOOR2Y + BOXSIZE - MARGIN)) && !(((posMario.x + vx) < (WINDOW_WIDTH - FLOOR2BOX * BOXSIZE - MARIO_WIDTH + heading * MARIO_WIDTH)) && (posMario.x + vx) > (FLOOR2BOX * BOXSIZE + heading * MARIO_WIDTH)) && (vy < 0)) 
		return 1;
	else if ((((posMario.y + vy) < FLOOR3Y + BOXSIZE) && ((posMario.y + vy) > FLOOR3Y + BOXSIZE - MARGIN)) && !(((posMario.x + vx) < (WINDOW_WIDTH - FLOOR3BOX * BOXSIZE - MARIO_WIDTH + heading * MARIO_WIDTH )) && (posMario.x + vx) > (FLOOR3BOX * BOXSIZE + heading * MARIO_WIDTH)) && (vy < 0)) 
		return 1;
	else if ((((posMario.y + vy) < FLOOR4Y + BOXSIZE) && ((posMario.y + vy) > FLOOR4Y + BOXSIZE - MARGIN)) && (((posMario.x + vx) > ((WINDOW_WIDTH - FLOOR4BOX * BOXSIZE) / 2 - MARIO_WIDTH + heading * MARIO_WIDTH)) && (posMario.x + vx) < (((WINDOW_WIDTH + FLOOR4BOX * BOXSIZE) / 2) + heading * MARIO_WIDTH)) && (vy < 0))
		return 1;
	else if ((((posMario.y + vy) < FLOOR5Y + BOXSIZE) && ((posMario.y + vy) > FLOOR5Y + BOXSIZE - MARGIN)) && !(((posMario.x + vx) < (WINDOW_WIDTH - FLOOR5BOX * BOXSIZE - MARIO_WIDTH + heading * MARIO_WIDTH )) && (posMario.x + vx) > (FLOOR5BOX * BOXSIZE + heading * MARIO_WIDTH)) && (vy < 0)) 
		return 1;
	return 0;

}


void Mario::fall(void)
{
	{
		sprite.move(Vector2f(0, vy));
	}
}

void Mario::move(WalkDirection dir)
{

	int speed=7;
	int wait = 60;
	switch (state) {
	case 1:
		
		if (dir == WalkDirection::Right)
		{
			sprite.move(sf::Vector2f(speed + MARIO_WIDTH,0));
			state = 8;

			vx = 0;
		}
		else if (dir == WalkDirection::Left)
		{
			sprite.move(sf::Vector2f(-speed,0));
			state = 2;
		}
		else if (isJump)
		{
			state = 6;
		}
		break;

	case 2:
		sf::sleep(sf::milliseconds(wait));
		if (dir == WalkDirection::Left)
		{
			sprite.move(sf::Vector2f(-speed, 0));
			state = 3;
		}
		else if (isJump)
		{
			state = 6;
			vx = -speed;
		}
		else
		{
			state = 1;
		}
		
		break;
	case 3:
		sf::sleep(sf::milliseconds(wait));
		if (dir == WalkDirection::Left && footstate == 0)
		{
			sprite.move(sf::Vector2f(-speed, 0));
			state = 4;
			footstate = 1;
		}
		else if (dir == WalkDirection::Left && footstate == 1)
		{
			sprite.move(sf::Vector2f(-speed, 0));
			state = 2;
			footstate = 0;
		}
		else if (isJump)
		{
			state = 6;
			vx = -speed;
		}
		else
		{
			state = 1;
		}
		break;
	case 4:
		sf::sleep(sf::milliseconds(wait));
		if (dir == WalkDirection::Left) 
		{
			sprite.move(sf::Vector2f(-speed, 0));
			state = 3;
		}
		else if (isJump)
		{
			state = 6;
			vx = -speed;
		}
		else
		{
			state = 1;
		}
		break;
	case 5:
		break;
	case 6:
		jump(0);
		//state = 1;
		break;
	case 7:
		fall();
		break;
	case 8:

		if (dir == WalkDirection::Left) 
		{
			sprite.move(sf::Vector2f(-speed - MARIO_WIDTH, 0));
			state = 1;
			vx=0;
		}
		else if (dir == WalkDirection::Right)
		{
			sprite.move(sf::Vector2f(speed, 0));
			state = 9;
		}
		else if (isJump)
		{
			state = 13;
		}
		break;

	case 9:
		sf::sleep(sf::milliseconds(wait));
		if (dir == WalkDirection::Right) 
		{
			sprite.move(sf::Vector2f(speed, 0));
			state = 10;
		}
		else if (isJump)
		{
			state = 13;
			vx = speed;
		}
		else
		{
			state = 8;
		}
		break;
	case 10:
		sf::sleep(sf::milliseconds(wait));
		if (dir == WalkDirection::Right && footstate == 0) 
		{
			sprite.move(sf::Vector2f(speed, 0));
			state = 11;
			footstate = 1;
		}
		else if (dir == WalkDirection::Right && footstate == 1)
		{
			sprite.move(sf::Vector2f(speed, 0));
			state = 9;
			footstate = 0;
		}
		else if (isJump)
		{
			state = 13;
			vx = speed;
		}
		else
		{
			state = 8;
		}
		break;
	case 11:
		sf::sleep(sf::milliseconds(wait));
		if (dir == WalkDirection::Right)
		{
			sprite.move(sf::Vector2f(speed, 0));
			state = 10;
		}
		else if (isJump)
		{
			state = 13;
			vx = speed;
		}
		else
		{
			state = 8;
		}
		break;
	case 12:
		break;
	case 13:
		jump(0);
		break;

	}
	
	
	if (state > 7){
		heading = 1;
		sprite.setTexture(textures[state-8]);
		sprite.setScale(-1, 1);
	}
	if (state <= 7) {
		heading = 0;
		sprite.setTexture(textures[state - 1]);
		sprite.setScale(1, 1);
	}
}