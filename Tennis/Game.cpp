#pragma once
#include "Game.h"

Game::Game() {
	window = new RenderWindow(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Mario");
	
	

	Background();
	mario.setPosition(Vector2f(((WINDOW_WIDTH - MARIO_WIDTH)/2), (FLOOR5Y - MARIO_HEIGHT)));
		
	for (int k = 0; k < 5; k++) {
		turtle[k].setPosition(Vector2f(-520000,-1000));
	}
	turtle[0].setPosition(Vector2f(PIPES_WIDTH, FLOOR5Y - TURTLE_HEIGHT - 50));
	turtleNo = 1;
	mario.isJump = 0;
	mario.isFall = 0;
	mario.footstate = 0;

	while (window->isOpen())
	{
		Event event;
				
		window->pollEvent(event);
		
		if (event.type == Event::Closed)
			window->close();

		if (turtleNo < 5) {
			if (turtle[turtleNo - 1].getposition().y > FLOOR4Y) {
				turtle[turtleNo].setPosition(Vector2f(PIPES_WIDTH, FLOOR5Y - TURTLE_HEIGHT - 50));
				turtleNo++;		
			} 						
		}

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

		for (int i = 0; i < 5; i++) {
			if (!turtle[i].onFloor()) {
				turtle[i].isJump = 1;
			}

			if (turtle[i].isJump) {
				turtle[i].move();
				turtle[i].jump();
			}
		}
		
		window->clear();

		for (int i = 0; i < 6 + FLOOR2BOX * 2 + FLOOR3BOX * 2 + FLOOR4BOX + FLOOR5BOX*2; i++) {
			window->draw(bgSprites[i]);
		}

		mario.draw(window);

		for (int i = 0; i < 5; i++) {
			turtle[i].move();
			turtle[i].draw(window);
			if (checkCollusion(&turtle[i], &mario, side)) {
				if (side == 20)
					turtle[i].state = 7;
				else if (side == 10)
					mario.state = 7;
			}
		}
		
		//cout << side << endl;
		window->display();
		
		//sf::sleep(sf::milliseconds(10));
	}
}

bool Game::checkCollusion(Turtle* t, Mario* m, int& side) {
	Vector2f posTurtle = t->getposition();
	Vector2f posMario = m->getposition();
	bool sideHitX = (posTurtle.x < posMario.x + MARIO_WIDTH + 5 && posTurtle.x > posMario.x + MARIO_WIDTH - 5)
		|| (posTurtle.x + TURTLE_WIDTH < posMario.x + 5 && posTurtle.x + TURTLE_WIDTH > posMario.x - 5);
	bool sideHitY = posMario.y + MARIO_HEIGHT <= posTurtle.y + TURTLE_HEIGHT && posMario.y + MARIO_HEIGHT >= posTurtle.y;
	bool headHit = posTurtle.x < posMario.x + 50 && posTurtle.x > posMario.x - 50;
	bool headHit2 = (posTurtle.y < posMario.y + MARIO_HEIGHT + 5 && posTurtle.y > posMario.y + MARIO_HEIGHT - 5);
	if (headHit2 && headHit)
		cout << 1 << endl;
	//cout << "sideHitX: " << sideHitX << endl;
	//cout << "sideHitY: " << sideHitY << endl;
	//cout << "headHit: " << headHit << endl;
	if (headHit && headHit2) {	// from head
		side = 20;
		return true;
	}
	else if (sideHitX && sideHitY) {	// from either side
		side = 10;
		return true;
	}
	return false;
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

