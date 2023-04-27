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
		if ((posMario.y + vy) > 892) {
			sprite.setPosition((posMario.x + vx), (892));
			vy = 0;
			vx = 0;
			isJump = 0;

			if (heading == 0) {
				state = 1;
			}
			if (heading == 1) {
				state = 8;
			}
		}


		if ((((posMario.y + vy) < 784)&&((posMario.y + vy)>662))&&!(((posMario.x + vx)<(1074+heading*66))&&(posMario.x + vx)>(780+heading*66)) && (vy<0)) {
			sprite.setPosition((posMario.x + vx),(784));
		
			vy = 0;
		}
		if ((((posMario.y + vy) < 784) && ((posMario.y + vy) > 662)) && !(((posMario.x + vx) < (1074 + heading * 56 - ~heading * 10)) && ((posMario.x + vx) > (780 + heading * 70 + ~heading * 10))) && (vy > 0)) {
			sprite.setPosition((posMario.x + vx), (662));
			vy = 0;
			vx = 0;
			isJump = 0;

			if (heading==0) {
				state = 1;
			}
			if (heading == 1) {
				state = 8;
			}
		}



		if ((((posMario.y + vy) < 559) && ((posMario.y + vy) > 437)) && !(((posMario.x + vx) < (1554 + heading * 66)) && (posMario.x + vx) > (300 + heading * 66)) && (vy < 0)) {
			sprite.setPosition((posMario.x + vx), (559));

			vy = 0;
		}
		if ((((posMario.y + vy) < 559) && ((posMario.y + vy) > 437)) && !(((posMario.x + vx) < (1554 + heading * 56 - ~heading * 10)) && ((posMario.x + vx) > (300 + heading * 70 + ~heading * 10))) && (vy > 0)) {
			sprite.setPosition((posMario.x + vx), (437));
			vy = 0;
			vx = 0;
			isJump = 0;

			if (heading == 0) {
				state = 1;
			}
			if (heading == 1) {
				state = 8;
			}
		}







		if ((((posMario.y + vy) < 434) && ((posMario.y + vy) > 312)) && (((posMario.x + vx) > (444 + heading * 66)) && (posMario.x + vx) < (1410 + heading * 66)) && (vy < 0)) {
			sprite.setPosition((posMario.x + vx), (434));
		
			vy = 0;
		}
		if ((((posMario.y + vy) < 434) && ((posMario.y + vy) > 312)) && (((posMario.x + vx) > (444 + heading * 56 - ~heading * 10)) && ((posMario.x + vx) < (1410 + heading * 70 + ~heading * 10))) && (vy > 0)) {
			sprite.setPosition((posMario.x + vx), (312));
			vy = 0;
			vx = 0;
			isJump = 0;

			if (heading == 0) {
				state = 1;
			}
			if (heading == 1) {
				state = 8;
			}
		}





		if ((((posMario.y + vy) < 234) && ((posMario.y + vy) > 112)) && !(((posMario.x + vx) < (1134 + heading * 66)) && (posMario.x + vx) > (720 + heading * 66)) && (vy < 0)) {
			sprite.setPosition((posMario.x + vx), (234));

			vy = 0;
		}
		if ((((posMario.y + vy) < 234) && ((posMario.y + vy) > 112)) && !(((posMario.x + vx) < (1134 + heading * 56 - ~heading * 10)) && ((posMario.x + vx) > (720 + heading * 70 + ~heading * 10))) && (vy > 0)) {
			sprite.setPosition((posMario.x + vx), (112));
			vy = 0;
			vx = 0;
			isJump = 0;

			if (heading == 0) {
				state = 1;
			}
			if (heading == 1) {
				state = 8;
			}
		}

		
		
		else 
		{ 
			sprite.move(Vector2f(vx, vy));
			vy += 3;
		}
	}
	if (down == 1)
	{

	}
}

void Mario::fall(void)
{
	{
		sprite.move(Vector2f(0, vy));
	}
}

void Mario::move(WalkDirection dir)
{

	int speed=10;
	switch (state) {
	case 1:
		
		if (dir == WalkDirection::Right)
		{
			sprite.move(sf::Vector2f(speed+60,0));
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
			sprite.move(sf::Vector2f(-speed-60, 0));
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