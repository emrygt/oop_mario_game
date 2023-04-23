#include "Game.h"

void Game::Background(void) {
	pipe.loadFromFile("../assets/pipe.png");
	pipe_texture1.setTexture(pipe);
	pipe_texture1.setOrigin({ 130, 100 });
	pipe_texture1.setScale({ -1,1 });
	pipe_texture1.setPosition({ 0,1000 });

	pipe_texture2.setTexture(pipe);
	pipe_texture2.setPosition({ 1800,900 });

	pipeS.loadFromFile("../assets/pipeS.png");
	pipeS_texture1.setTexture(pipeS);
	pipeS_texture1.setOrigin({ 130, 100 });
	pipeS_texture1.setScale({ -1,1 });
	pipeS_texture1.setPosition({ 1790,250 });

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
		//brick_textures[i].setScale(2,2);
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

	
	soldier.setPosition(Vector2f(float(rand() % (WINDOW_WIDTH - 100)), float(rand() % (WINDOW_HEIGHT - 100))));

}

void Game::update(void)

{
	while (window->isOpen())
	{
		Event event;

		while (window->pollEvent(event))
		{
			if (event.type == Event::Closed)
				window->close();
			if (event.type == sf::Event::KeyPressed)
			{
				
				if (event.key.code == sf::Keyboard::Right)
				{
					soldier.walk( Soldier::WalkDirection::Right);
				}
				else if (event.key.code == sf::Keyboard::Left)
				{
					soldier.walk(Soldier::WalkDirection::Left);
				}
				else if (event.key.code == sf::Keyboard::Up)
				{
					soldier.walk(Soldier::WalkDirection::Up);
				}
				else if (event.key.code == sf::Keyboard::Down)
				{
					soldier.walk(Soldier::WalkDirection::Down);
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
		
		//test
		
		soldier.draw(window);

		

		window->display();

		sf::sleep(sf::milliseconds(1000/speed));
	}
}