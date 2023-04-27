#include "Common.h"
#include "Mario.h"

class Game
{
	
	Texture bgTextures[4];
	Sprite* bgSprites;
	Mario mario;

public:
	Game();
	RenderWindow* window;
	void Background(void);
};