#include "Common.h"
#include "Mario.h"
#include "Object.h"

class Game
{
	
	Texture pipe, pipeS, floor, brick;
	Sprite pipe_texture1, pipe_texture2, pipeS_texture1, pipeS_texture2, floor_texture1, floor_texture2;
	Sprite* brick_textures;
	int speed, a;
	Mario mario;

public:
	RenderWindow* window;
	Game(int);
	void update(void);
	void Background(void);
};