#include "Background.h"
#include "Game.h"

Background::Background(void) {
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
	pipeS_texture1.setPosition({ 1790,150 });

	pipeS_texture2.setTexture(pipeS);
	pipeS_texture2.setPosition({ 0, 50 });

	floor.loadFromFile("../assets/floor.png");
	floor_texture1.setTexture(floor);
	floor_texture1.setPosition({ 0,970 });
	floor_texture2.setTexture(floor);
	floor_texture2.setPosition({ 960,970 });


}