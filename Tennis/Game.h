#include "Common.h"
#include "Mario.h"

class Game
{
	
	Texture bgTextures[4];
	Sprite* bgSprites;
	Mario mario;

public:
	RenderWindow* window;
	Game();
	void Background(void);
};