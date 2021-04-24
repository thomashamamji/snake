#include "common.h"

void prepareScene(App * app)
{
	SDL_SetRenderDrawColor(app->renderer, 96, 128, 255, 255);
	SDL_RenderClear(app->renderer);
}

void presentScene(App * app)
{
	SDL_RenderPresent(app->renderer);
}

void blit(App app, SDL_Texture *texture, int x, int y)
{
	SDL_Rect dest;

	dest.x = x;
	dest.y = y;
	SDL_QueryTexture(texture, NULL, NULL, &dest.w, &dest.h);

	SDL_RenderCopy(app.renderer, texture, NULL, &dest);
}

void transfert_boards (App * app, Entity * e) {
	int w, h;
	SDL_GetWindowSize(app->window, &w, &h);

	if (e->x <= -30) {
		e->x += w + 30; // Inverse position & applying diameter changes
	}

	if (e->x >= w + 30) {
		e->x -= w + 30; // Inverse position & applying diameter changes
	}

	if (e->y <= -30) {
		e->y += h + 30; // Inverse position & applying diameter changes
	}

	if (e->y >= h + 30) {
		e->y -= h + 30; // Inverse position & applying diameter changes
	}
}

int ** generate_points (App * app, unsigned int * H, unsigned int * L) {
	int w, h;
	SDL_GetWindowSize(app->window, &w, &h);

	int ** points = calloc(*H, sizeof(int*)); // 15 : icons size

	// Call srand

	*H = h / 15;
	*L = w / 15;

	for (int y = 0; y < *H; y++) {
		points[y] = (int*) calloc(*L, sizeof(int));
		for (int x = 0; x < *L; x++) {
			points[y][x] = rand() % 8;
		}
	}

	return points;
}

void consoleDisplayPoints (int ** points, unsigned int H, unsigned int L) {
	for (int y = 0; y < H; y++) {
		for (int x = 0; x < L; x++) {
			printf("%d ", points[y][x]);
		}
		printf("\n");
	}
}

void map_points(App * app, Points * P, int ** points, unsigned int H, unsigned int L) {
	unsigned int i = 0;

	for (int y = 0; y < H; y++) {
		for (int x = 0; x < L; x++) {
			if (points[y][x] == 3) {
				P[i].value = points[y][x];
				P[i].location.x = 15 * x;
				P[i].location.y = 15 * y;
				P[i++].location.texture = loadTexture(*app, "medias/points.png");
			}
		}
	}
}

void blitPoints (App app, Points * P, unsigned int n) {
	for (int i = 0; i < n; i++) {
		blit(app, P[i].location.texture, P[i].location.x, P[i].location.y);
	}
}

void free_points (int ** points, unsigned int H) {
	for (int x = 0; x < H; x++) {
		free(points[x]);
	}
	free(points);
}