#include "Common.h"
#include "Mario.h"

class Game
{
	RenderWindow* window;
	Texture pipe, pipeS, floor, brick;
	Sprite pipe_texture1, pipe_texture2, pipeS_texture1, pipeS_texture2, floor_texture1, floor_texture2;
	Sprite* brick_textures;
	int speed;
	Mario mario;

public:
	Game(int);
	void update(void);
	void Background(void);

	
};