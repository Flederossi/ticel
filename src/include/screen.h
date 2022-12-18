#include <SDL2/SDL.h>

#include "config.h"

const int check_btns[] = {SDL_BUTTON_LEFT, SDL_BUTTON_RIGHT, SDL_BUTTON_MIDDLE};
const int check_keys[] = {SDLK_s, SDLK_ESCAPE, SDLK_r};
const char *modes[] = {"edit", "simulate"};

SDL_Rect rect;

int psw, psh;

SDL_Window *w;
SDL_Renderer *r;
SDL_Event e;

int screenSetTitle(int s, char *rs){
	char title[512];
	sprintf(title, "ticel | %s | %s", rs, modes[s]);
	SDL_SetWindowTitle(w, title);
}

void screenInit(char *rs){
	SDL_Init(SDL_INIT_VIDEO);
	SDL_CreateWindowAndRenderer(W, H, 0, &w, &r);
	screenSetTitle(0, rs);
	SDL_RenderPresent(r);
}

int screenGetMouse(int *x, int *y){
	SDL_GetMouseState(x, y);
}

int screenCheckQuit(){
	SDL_PollEvent(&e);
	return e.type == SDL_QUIT ? 0 : 1;
}

int screenCheckMouse(){
	SDL_PollEvent(&e);
	if (e.type == SDL_MOUSEBUTTONDOWN || e.type == SDL_MOUSEMOTION){
		for (int i = 0; i < sizeof(check_btns) / sizeof(int); i++){
			if (e.button.button == check_btns[i]){
				return i + 1;
			}
		}
	}
	return 0;
}

int screenCheckKey(){
	SDL_PollEvent(&e);
	if (e.type == SDL_KEYUP){
		for (int i = 0; i < sizeof(check_keys) / sizeof(int); i++){
			if (e.key.keysym.sym == check_keys[i]){
				return i + 1;
			}
		}
	}
	return 0;
}

int screenClear(){
	SDL_SetRenderDrawColor(r, 0, 0, 0, 255);
	SDL_RenderClear(r);
}

int screenDraw(int x, int y){
	psw = rect.w = W / GS;
	psh = rect.h = H / GS;
	rect.x = x * psw;
	rect.y = y * psh;
	SDL_SetRenderDrawColor(r, 255, 255, 255, 255);
	SDL_RenderFillRect(r, &rect);
}

int screenRender(){
	SDL_RenderPresent(r);
}

void screenDelay(int t){
	SDL_Delay(t);
}

void screenDestroy(){
	SDL_DestroyRenderer(r);
	SDL_DestroyWindow(w);
	SDL_Quit();
}