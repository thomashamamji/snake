#include "common.h"

App app;
Entity player;

int main(int argc, char *argv[])
{
	// memset(&app, 0, sizeof(App));

	initSDL(&app);

    player.x = 100;
	player.y = 100;
	player.texture = loadTexture(app, "medias/snake_right.png");
    unsigned int direction = 1;
    unsigned int L, H;

    int ** points = generate_points(&app, &H, &L);
    
    // consoleDisplayPoints(points, H, L);

    Points * P = malloc(L * H * sizeof(Points));

    map_points(&app, P, points, H, L);

	while (1)
	{
		prepareScene(&app);

		doInput(&direction);

        switch (direction)
        {
            case 1 :
                // Left -> Right
                player.x = player.x + 1;
                player.texture = loadTexture(app, "medias/snake_right.png");
            break;

            case 2 :
                // Bot -> Top
                player.y = player.y - 1;
                // Change icon
                player.texture = loadTexture(app, "medias/snake_up.png");
            break;

            case 3 :
                // Right -> Left
                player.x = player.x - 1;
                // Change icon
                player.texture = loadTexture(app, "medias/snake_left.png");
            break;

            case 4 :
                // Top -> Bot
                player.y = player.y + 1;
                // Change icon
                player.texture = loadTexture(app, "medias/snake_down.png");
            break;

            default: break;
        }

        transfert_boards(&app, &player);

        blit(app, player.texture, player.x, player.y);
        printf("(%d,%d)", player.x, player.y);
        blitPoints(app, P, L * H);

		presentScene(&app);

		SDL_Delay(16);
	}

    free(P);
    P = NULL;
    free_points(points, H);
    points = NULL;

	return 0;
}