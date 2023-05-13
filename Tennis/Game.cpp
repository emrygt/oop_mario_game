#pragma once
#include "Game.h"

Game::Game() {
	window = new RenderWindow(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Mario");
	
	

	Background();
	mario.setPosition(Vector2f(((WINDOW_WIDTH - MARIO_WIDTH)/2), (FLOOR5Y - MARIO_HEIGHT)));//892 312
	turtle.setPosition(Vector2f(400, (FLOOR1Y - TURTLE_HEIGHT)));//892 312
	mario.isJump = 0;
	mario.isFall = 0;
	mario.footstate = 0;

	while (window->isOpen())
	{
		Event event;
		
		cout << mario.isPipeHit() << endl;
		window->pollEvent(event);
		
		if (event.type == Event::Closed)
			window->close();
		
		if ((mario.state != 1 && mario.state != 8) && (event.type != sf::Event::KeyPressed)) //mario will stay subtle if there is now key pressed
		{
			mario.move(mario.WalkDirection::Null);
		}
		if ((event.type == sf::Event::KeyPressed) || (mario.state!=1 && mario.state != 8))
		{
		
			
			if (event.key.code == sf::Keyboard::Right)
			{
				mario.move(mario.WalkDirection::Right);
			}
			if (event.key.code == sf::Keyboard::Left)
			{
				mario.move(mario.WalkDirection::Left);
			}
			if ((event.key.code == sf::Keyboard::Space && !mario.isJump))
			{
				mario.isJump = 1;
				mario.vy = -24;	// initial jump speed
			}
			if (mario.isJump)
			{
				mario.move(mario.WalkDirection::Null);
			}			
			if (event.key.code == sf::Keyboard::F && !mario.isFall)
			{
				mario.isFall = 1;
				mario.vy = 0;
				mario.state = 7;
			}
			if (mario.isFall)
			{
				mario.move(mario.WalkDirection::Null);
				mario.vy += 3;
			}
		}		

		if (!mario.onFloor()) {
			mario.jump(1);
		}

		if (!turtle.onFloor()) {
			turtle.isJump = 1;
		}

		if (turtle.isJump) {
			turtle.move();
			turtle.jump();
		}

		window->clear();

		for (int i = 0; i < 6 + FLOOR2BOX * 2 + FLOOR3BOX * 2 + FLOOR4BOX + FLOOR5BOX*2; i++) {
			window->draw(bgSprites[i]);
		}


		mario.draw(window);
		turtle.draw(window);
		turtle.move();

		window->display();
		
		//sf::sleep(sf::milliseconds(10));
	}
}

void Game::Background(void) {


	bgSprites = new Sprite[6 + FLOOR2BOX * 2 + FLOOR3BOX * 2 + FLOOR4BOX + FLOOR5BOX * 2];

	bgTextures[0].loadFromFile("../assets/pipe.png");
	bgSprites[0].setTexture(bgTextures[0]);
	bgSprites[0].setScale({ -1,1 });
	bgSprites[0].setPosition({ 120,900 });
	bgSprites[1].setTexture(bgTextures[0]);
	bgSprites[1].setPosition({ 1800,900 });

	bgTextures[1].loadFromFile("../assets/pipeS.png");
	bgSprites[2].setTexture(bgTextures[1]);
	bgSprites[2].setScale({ -1,1 });
	bgSprites[2].setPosition({ WINDOW_WIDTH,75 });
	bgSprites[3].setTexture(bgTextures[1]);
	bgSprites[3].setPosition({ 0, 75 });

	bgTextures[2].loadFromFile("../assets/floor.png");
	bgSprites[4].setTexture(bgTextures[2]);
	bgSprites[4].setPosition({ 0,FLOOR1Y });
	bgSprites[5].setTexture(bgTextures[2]);
	bgSprites[5].setPosition({ WINDOW_WIDTH/2,FLOOR1Y });

	

	bgTextures[3].loadFromFile("../assets/brick.png");

	for (int i = 0; i < FLOOR2BOX * 2 + FLOOR3BOX * 2 + FLOOR4BOX + FLOOR5BOX * 2; i++) {
		bgSprites[i + 6].setTexture(bgTextures[3]);
	}
	for (int i = 0; i < FLOOR2BOX; i++) {
		bgSprites[i + 6].setPosition({float(i * BOXSIZE), FLOOR2Y });
	}
	for (int i = 0; i < FLOOR2BOX; i++) {
		bgSprites[i + 6+ FLOOR2BOX].setPosition({ float(WINDOW_WIDTH-BOXSIZE* FLOOR2BOX + i * BOXSIZE), FLOOR2Y });
	}
	for (int i = 0; i < FLOOR3BOX; i++) {
		bgSprites[i + 6+ FLOOR2BOX*2].setPosition({ float(i * BOXSIZE), FLOOR3Y });
	}
	for (int i = 0; i < FLOOR3BOX; i++) {
		bgSprites[i + 6 + FLOOR2BOX * 2+ FLOOR3BOX].setPosition({ float(WINDOW_WIDTH - BOXSIZE * FLOOR3BOX + i * BOXSIZE), FLOOR3Y });
	}
	for (int i = 0; i < FLOOR4BOX; i++) {
		bgSprites[i + 6 + FLOOR2BOX * 2 + FLOOR3BOX *2].setPosition({ float((WINDOW_WIDTH - BOXSIZE * FLOOR4BOX)/2  + i * BOXSIZE), FLOOR4Y });
	}
	for (int i = 0; i < FLOOR5BOX; i++) {
		bgSprites[i + 6 + FLOOR2BOX * 2 + FLOOR3BOX * 2 + FLOOR4BOX].setPosition({ float(i * BOXSIZE), FLOOR5Y });
	}
	for (int i = 0; i < FLOOR5BOX; i++) {
		bgSprites[i + 6 + FLOOR2BOX * 2 + FLOOR3BOX * 2 + FLOOR4BOX + FLOOR5BOX].setPosition({ float(WINDOW_WIDTH - BOXSIZE * FLOOR5BOX + i * BOXSIZE), FLOOR5Y });
	}
}

