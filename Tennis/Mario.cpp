#include "Mario.h"
#include "Game.h"



Mario::Mario()
{
	char path[64];
	for (int i = 0; i < 14; i++) 
	{
		sprintf_s(path, "../assets/soldier%d.png", i);
		textures[i].loadFromFile(path);
	}

	state = 0;
	footstate = 0;
	speed = 12;
	sprite.setTexture(textures[state]);
	//texture.loadFromFile("../assets/soldier0.png");
	//sprite.setTexture(texture);
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
	case 0:
		if (dir == WalkDirection::Up && footstate == 1)   //up direction
		{
			sprite.move(sf::Vector2f(0, -speed));
			state = 8;
		}
		else if (dir == WalkDirection::Up && footstate == 0)
		{
			sprite.move(sf::Vector2f(0, -speed));
			state = 7;
			
		}
		else if (dir == WalkDirection::Left || dir == WalkDirection::Down)
		{
			state = 7;
		}
		else if (dir == WalkDirection::Right)
		{

			cout << "k" << endl;
			state = 1;
		}
		break;
	case 1:
		if (dir == WalkDirection::Right || dir == WalkDirection::Down)
			state = 2;
		else if (dir == WalkDirection::Left || dir == WalkDirection::Up)
			state = 0;
		break;
	case 2:
		if (dir == WalkDirection::Right && footstate == 1)   //up direction
		{
			sprite.move(sf::Vector2f(speed,0));
			state = 9;
		}
		else if (dir == WalkDirection::Right && footstate == 0)
		{
			sprite.move(sf::Vector2f(speed, 0));
			state = 10;
		}
		else if (dir == WalkDirection::Left || dir == WalkDirection::Up)
		{
			state = 1;
		}
		else if (dir == WalkDirection::Down)
		{
			state = 3;
		}
		break;
	case 3:
		footstate = 1;
		if (dir == WalkDirection::Up || dir == WalkDirection::Right)
			state = 2;
		else if (dir == WalkDirection::Left || dir == WalkDirection::Down)
		{
			sprite.move(sf::Vector2f(0 , speed));
			state = 4;
		}
			break;
	case 4:
		if (dir == WalkDirection::Down && footstate == 1)   //up direction
		{
			sprite.move(sf::Vector2f(0, speed));
			state = 11;
		}
		else if (dir == WalkDirection::Down && footstate == 0)
		{
			sprite.move(sf::Vector2f(0, speed));
			state = 3;
		}
		else if (dir == WalkDirection::Right || dir == WalkDirection::Up)
		{
			state = 3;
		}
		else if (dir == WalkDirection::Left)
		{
			state = 5;
		}
		break;
	case 5:
		if (dir == WalkDirection::Down || dir == WalkDirection::Right)
			state = 4;
		else if (dir == WalkDirection::Left || dir == WalkDirection::Up)
			state = 6;
		break;
	case 6:
		if (dir == WalkDirection::Left && footstate == 1)   //up direction
		{
			sprite.move(sf::Vector2f(-speed , 0));
			state = 12;
		}
		else if (dir == WalkDirection::Left && footstate == 0)
		{
			sprite.move(sf::Vector2f(-speed, 0));
			state = 13;
		}
		else if (dir == WalkDirection::Right || dir == WalkDirection::Down)
		{
			state = 5;
		}
		else if (dir == WalkDirection::Up)
		{
			state = 7;
		}
		break;
	case 7:
		footstate = 1;
		if (dir == WalkDirection::Up || dir == WalkDirection::Right)
		{
			state = 0;
		}
		else if (dir == WalkDirection::Left || dir == WalkDirection::Down)
			state = 6;
		break;
	case 8:
		footstate = 0;
		sprite.move(sf::Vector2f(0, -speed));
		state = 0;
		break;
	case 9:
		footstate = 0;
		sprite.move(sf::Vector2f(speed, 0));
		state = 2;
		break;
	case 10:
		footstate = 1;
		sprite.move(sf::Vector2f(speed, 0));
		state = 2;
		break;
	case 11:
		footstate = 0;
		sprite.move(sf::Vector2f(0, speed));
		state = 4;
		break;
	case 12:
		footstate = 0;
		sprite.move(sf::Vector2f(-speed, 0));
		state = 6;
		break;
	case 13:
		footstate = 1;
		sprite.move(sf::Vector2f(-speed, 0));
		state = 6;
		break;

	}
	cout << state << endl;
	sprite.setTexture(textures[state]);
}