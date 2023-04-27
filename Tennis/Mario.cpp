#include "Mario.h"


Mario::Mario ()
{
	char path[64];
	for (int i = 1; i < 8; i++) 
	{
		sprintf_s(path, "../assets/mario%d.png", i);
		textures[i - 1].loadFromFile(path);
		textures[i + 6].loadFromFile(path); 
	}

	state = 1;
	footstate = 0;
	speed = 10;
	sprite.setTexture(textures[state]);
}



void Mario::draw(RenderWindow* window)
{
	window->draw(sprite);
}

void Mario::jump(bool down)
{
	if (down == 0)
	{
		
		{
		sprite.move(Vector2f(vx, vy));
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

void Mario::walk(WalkDirection dir)
{
	
	switch (state) {
	case 1:
		if (dir == WalkDirection::Right)
		{
			sprite.move(sf::Vector2f(speed+60,0));
			state = 8;
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
	
	sprite.setTexture(textures[state-1]);
	if (state > 7)
		sprite.setScale(-1, 1);
	if (state < 7) {
		sprite.setScale(1, 1);
	}
}