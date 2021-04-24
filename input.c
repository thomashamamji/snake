#include "common.h"

void doInput(unsigned int * direction)
{
	SDL_Event event;

	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
			case SDL_QUIT:
				exit(0);
			break;
            case SDL_KEYDOWN :
                switch (event.key.keysym.sym) {
                    case SDLK_RIGHT :
                        *direction = 1;
                    break;
                    case SDLK_UP :
                        *direction = 2;
                    break;
                    case SDLK_LEFT :
                        *direction = 3;
                    break;
                    case SDLK_DOWN :
                        *direction = 4;
                    break;
                }
            break;

			default:
				break;
		}
	}
}