#include "Game.h"

Game::Game() {
	window = new RenderWindow(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Mario");
	Background();
	mario.setPosition(Vector2f((300), (500)));

	mario.isJump = 0;
	mario.isFall = 0;

	while (window->isOpen())
	{
		Event event;

		window->pollEvent(event);
		{
			if (event.type == Event::Closed)
				window->close();

			if ((event.type == sf::Event::KeyPressed) || mario.isJump || mario.isFall)
			{
				cout << event.key.code << endl;

				if (event.key.code == sf::Keyboard::Right && !(event.key.code == sf::Keyboard::Left))
				{
					mario.walk(Mario::WalkDirection::Right);
					if (mario.isJump)
					{
						mario.sprite.move(Vector2f(0, 0));
					}
				}
				if (event.key.code == sf::Keyboard::Left && !(event.key.code == sf::Keyboard::Right))
				{
					mario.walk(Mario::WalkDirection::Left);
					if (mario.isJump)
					{
						mario.sprite.move(Vector2f(0, 0));
					}
				}
				if ((event.key.code == sf::Keyboard::Space && !mario.isJump))
				{
					mario.isJump = 1;
					mario.vy = -50;
				}
				if (mario.isJump)
				{
					mario.walk(Mario::WalkDirection::Space);
					mario.vy += 5;
				}
				if (event.key.code == sf::Keyboard::F && !mario.isFall)
				{
					mario.isFall = 1;
					mario.vy = 0;
					mario.state = 7;
				}
				if (mario.isFall)
				{
					mario.walk(Mario::WalkDirection::Space);
					mario.vy += 3;
				}
			}
		}

		window->clear();



		for (int i = 0; i < 156; i++) {
			window->draw(bgSprites[i]);
		}


		mario.draw(window);


		window->display();

		sf::sleep(sf::milliseconds(100));
	}
}

void Game::Background(void) {


	bgSprites = new Sprite[156];

	bgTextures[0].loadFromFile("../assets/pipe.png");
	bgSprites[0].setTexture(bgTextures[0]);
	bgSprites[0].setScale({ -1,1 });
	bgSprites[0].setPosition({ 120,900 });
	bgSprites[1].setTexture(bgTextures[0]);
	bgSprites[1].setPosition({ 1800,900 });

	bgTextures[1].loadFromFile("../assets/pipeS.png");
	bgSprites[2].setTexture(bgTextures[1]);
	bgSprites[2].setScale({ -1,1 });
	bgSprites[2].setPosition({ 1920,150 });
	bgSprites[3].setTexture(bgTextures[1]);
	bgSprites[3].setPosition({ 0, 150 });

	bgTextures[2].loadFromFile("../assets/floor.png");
	bgSprites[4].setTexture(bgTextures[2]);
	bgSprites[4].setPosition({ 0,980 });
	bgSprites[5].setTexture(bgTextures[2]);
	bgSprites[5].setPosition({ 960,980 });

	

	bgTextures[3].loadFromFile("../assets/brick.png");

	for (int i = 0; i < 150; i++) {
		bgSprites[i + 6].setTexture(bgTextures[3]);
	}
	for (int i = 0; i < 26; i++) {
		bgSprites[i + 6].setPosition({float(i * 30), 750});
	}
	for (int i = 0; i < 26; i++) {
		bgSprites[i + 32].setPosition({ float(1140 + i * 30), 750 });
	}
	for (int i = 0; i < 10; i++) {
		bgSprites[i + 58].setPosition({ float(i * 30), 525 });
	}
	for (int i = 0; i < 10; i++) {
		bgSprites[i + 68].setPosition({ float(1620 + i * 30), 525 });
	}
	for (int i = 0; i < 30; i++) {
		bgSprites[i + 78].setPosition({ float(480 + i * 30), 480 });
	}
	for (int i = 0; i < 24; i++) {
		bgSprites[i + 108].setPosition({ float(i * 30), 300 });
	}
	for (int i = 0; i < 24; i++) {
		bgSprites[i + 132].setPosition({ float(1200 + i * 30), 300 });
	}
}

