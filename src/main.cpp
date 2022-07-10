#include "Game.hpp"

Game *game = nullptr;
//Player *player = nullptr;
int main(int argv, char** args)
{
	//player = new Player();
	//player -> run (12,12);
	const int FPS = 60;
	const int frameDelay = 1000 / FPS;
	Uint32 frameStart;
	int frameTime;

	game = new Game();
	game -> init("Hugo The Game 3", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 32*25, 32*20, false );

	std::cout << "MAP";

	while (game -> running()){
		frameStart = SDL_GetTicks();
		game -> update();
		game -> handleEvents();
		game -> render();

		frameTime = SDL_GetTicks() - frameStart;
		if (frameDelay > frameTime)
		{
			SDL_Delay(frameDelay - frameTime);
		}
		
	}
	
	game -> clean();



	/* code */
	return 0;
}