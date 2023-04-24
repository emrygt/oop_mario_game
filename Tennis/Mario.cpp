#include "Mario.h"
#include "Game.h"



Mario::Mario()
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
	speed = 12;
	sprite.setTexture(textures[state]);
}

void Mario::setPosition(Vector2f pos)
{
	this->pos = pos;
	sprite.setPosition(pos);
}

void Mario::draw(RenderWindow* window)
{
	window->draw(sprite);
}

void Mario::walk(WalkDirection dir)
{
	
	switch (state) {
	case 1:
		if (dir == WalkDirection::Right)   //up direction
		{
			sprite.move(sf::Vector2f(speed,0));
			state = 8;
			sprite.setPosition(sprite.getPosition() + Vector2f(65, 0));
		}
		else if (dir == WalkDirection::Left)
		{
			sprite.move(sf::Vector2f(-speed,0));
			state = 2;
		}
		break;

	case 2:
		if (dir == WalkDirection::Left)   //up direction
		{
			sprite.move(sf::Vector2f(-speed, 0));
			state = 3;
		}
		else
		{
			state = 1;
		}
		break;
	case 3:
		if (dir == WalkDirection::Left && footstate == 0)   //up direction
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
		else
		{
			state = 1;
		}
		break;
	case 4:
		if (dir == WalkDirection::Left)   //up direction
		{
			sprite.move(sf::Vector2f(-speed, 0));
			state = 3;
		}
		else
		{
			state = 1;
		}
		break;
	case 5:
		break;
	case 6:
		break;
	case 7:
		break;
	case 8:
		if (dir == WalkDirection::Left)   //up direction
		{
			sprite.move(sf::Vector2f(-speed, 0));
			state = 1;
			sprite.setPosition(sprite.getPosition() - Vector2f(65, 0));
		}
		else if (dir == WalkDirection::Right)
		{
			sprite.move(sf::Vector2f(speed, 0));
			state = 9;
		}

		
		break;

	case 9:
		if (dir == WalkDirection::Right)   //up direction
		{
			sprite.move(sf::Vector2f(speed, 0));
			state = 10;
		}
		else
		{
			state = 8;
		}
		break;
	case 10:
		if (dir == WalkDirection::Right && footstate == 0)   //up direction
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
		else
		{
			state = 8;
		}
		break;
	case 11:
		if (dir == WalkDirection::Right)   //up direction
		{
			sprite.move(sf::Vector2f(speed, 0));
			state = 10;
		}
		else
		{
			state = 8;
		}
		break;
	case 12:
		break;
	case 13:
		break;

	}
	cout << state << endl;
	
	sprite.setTexture(textures[state-1]);
	if (state > 7)
		sprite.setScale(-1, 1);
	if (state <= 7) {
		sprite.setScale(1, 1);
		//Vector2f b = 
	}
}