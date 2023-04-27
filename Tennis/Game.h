#include "Common.h"
#include "Mario.h"

class Game
{
	
	Texture bgTextures[4];
	Sprite* brick_textures;
	Sprite* bgSprites;
	int speed;
	Mario mario;

public:
	RenderWindow* window;
	Game(int);
	void update(void);
	void Background(void);
};