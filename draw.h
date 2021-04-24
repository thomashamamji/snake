#ifndef __DRAW_H__
#define __DRAW_H__

void prepareScene(App * app);
void presentScene(App * app);
void blit(App app, SDL_Texture *texture, int x, int y);
void transfert_boards (App * app, Entity * e);
int ** generate_points (App * app, unsigned int * H, unsigned int * L);
void consoleDisplayPoints (int ** points, unsigned int H, unsigned int L);
void map_points(App * app, Points * P, int ** points, unsigned int H, unsigned int L);
void blitPoints (App app, Points * P, unsigned int n);
void free_points (int ** points, unsigned int H);

#endif