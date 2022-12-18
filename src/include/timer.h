#include <SDL2/SDL.h>

int start;

void timerSetStart(){
	start = SDL_GetTicks();
}

int timerAddTicks(int *ela){
	ela += SDL_GetTicks() - start;
}