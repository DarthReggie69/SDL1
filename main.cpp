#include <SDL.h>


SDL_Window* g_pWindow = 0;
SDL_Renderer* g_pRenderer = 0;

int main(int argc, char* args[])
{
	SDL_Init(SDL_INIT_EVERYTHING);

	SDL_SetRenderDrawColor(g_pRenderer, 0, 0, 255, 255);

	SDL_RenderClear(g_pRenderer);

	SDL_RenderPresent(g_pRenderer);

	SDL_Delay(15000);















	return 0; 
}