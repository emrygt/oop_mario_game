#include "Game.h"

void Game::Background(void) {
	pipe.loadFromFile("../assets/pipe.png");
	pipe_texture1.setTexture(pipe);
	pipe_texture1.setOrigin({ 130, 0 });
	pipe_texture1.setScale({ -1,1 });
	pipe_texture1.setPosition({ 0,900 });

	pipe_texture2.setTexture(pipe);
	pipe_texture2.setPosition({ 1800,900 });

	pipeS.loadFromFile("../assets/pipeS.png");
	pipeS_texture1.setTexture(pipeS);
	pipeS_texture1.setOrigin({ 130, 0 });
	pipeS_texture1.setScale({ -1,1 });
	pipeS_texture1.setPosition({ 1790,150 });

	pipeS_texture2.setTexture(pipeS);
	pipeS_texture2.setPosition({ 0, 150 });

	floor.loadFromFile("../assets/floor.png");
	floor_texture1.setTexture(floor);
	floor_texture1.setPosition({ 0,980 });
	floor_texture2.setTexture(floor);
	floor_texture2.setPosition({ 960,980 });

	brick_textures = new Sprite[150];

	brick.loadFromFile("../assets/brick.png");

	for (int i = 0; i < 150; i++) {
		brick_textures[i].setTexture(brick);
	}
	for (int i = 0; i < 26; i++) {
		brick_textures[i].setPosition({float(i * 30), 750});
	}
	for (int i = 0; i < 26; i++) {
		brick_textures[i+26].setPosition({ float(1140 + i * 30), 750 });
	}
	for (int i = 0; i < 10; i++) {
		brick_textures[i + 52].setPosition({ float(i * 30), 525 });
	}
	for (int i = 0; i < 10; i++) {
		brick_textures[i + 62].setPosition({ float(1620 + i * 30), 525 });
	}
	for (int i = 0; i < 30; i++) {
		brick_textures[i + 72].setPosition({ float(480 + i * 30), 480 });
	}
	for (int i = 0; i < 24; i++) {
		brick_textures[i + 102].setPosition({ float(i * 30), 300 });
	}
	for (int i = 0; i < 24; i++) {
		brick_textures[i + 126].setPosition({ float(1200 + i * 30), 300 });
	}
}

Game::Game(int speed) {
	this->speed = speed;
	window = new RenderWindow(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Mario");
	Background();

	
	mario.setPosition(Vector2f((300), (300)));

}

void Game::update(void)

{
	mario.isJump = 0;
	mario.isFall = 0;
	
	while (window->isOpen())
	{
		Event event;
		
		window->pollEvent(event);
		{
			if (event.type == Event::Closed)
				window->close();

			if ((event.type == sf::Event::KeyPressed) ||mario.isJump || mario.isFall)
			{
				
 				if (event.key.code == sf::Keyboard::Right)
				{
					mario.walk(Mario::WalkDirection::Right);
				}
				else if (event.key.code == sf::Keyboard::Left)
				{
					mario.walk(Mario::WalkDirection::Left);
				}
   				else if ((event.key.code == sf::Keyboard::Space && !mario.isJump))
				{
					mario.isJump = 1;	
					mario.vy = -50;
				}
				else if (mario.isJump)
				{
					mario.walk(Mario::WalkDirection::Space);
					mario.vy += 5;
				}
				else if (event.key.code == sf::Keyboard::F && !mario.isFall)
				{
					mario.isFall = 1;
					mario.vy = 0;
					mario.state = 7;
				}
				else if (mario.isFall)
				{
					mario.walk(Mario::WalkDirection::Space);
					mario.vy += 3;
				}
			}
		}

		window->clear();

		window->draw(pipe_texture1);
		window->draw(pipe_texture2);
		window->draw(pipeS_texture1);
		window->draw(pipeS_texture2);
		window->draw(floor_texture1);
		window->draw(floor_texture2);

		for (int i = 0; i < 150; i++) {
			window->draw(brick_textures[i]);
		}
		
		
		mario.draw(window);
		

		window->display();

		sf::sleep(sf::milliseconds(1000/speed));
	}
}