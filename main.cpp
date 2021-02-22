#include <iostream>
#include <SDL.h>






bool init();


bool loadMedia();     


void close();


SDL_Window* gameWindow = NULL;


SDL_Surface* gScreenSurface = NULL;


SDL_Surface* gHelloThere = NULL;

bool init()
{

    bool success = true;


    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        success = false;
    }
    else
    {

        gameWindow = SDL_CreateWindow("Mood Killers ", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1280, 720, SDL_WINDOW_SHOWN);
        if (gameWindow == NULL)
        {
            printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
            success = false;
        }
        else
        {

            gScreenSurface = SDL_GetWindowSurface(gameWindow);
        }
    }

    return success;
}

bool loadMedia()
{

    bool success = true;


    gHelloThere = SDL_LoadBMP("Pictures/background.bmp");
    if (gHelloThere == NULL)
    {
        printf("Unable to load image %s! SDL Error: %s\n", "Pictures/background.bmp", SDL_GetError());
        success = false;
    }

    return success;
}

void close()
{

    SDL_FreeSurface(gHelloThere);
    gHelloThere = NULL;


    SDL_DestroyWindow(gameWindow);
    gameWindow = NULL;


    SDL_Quit();
}


int main(int argc, char* args[])
{

    if (!init())
    {
        printf("Failed to initialize!\n");
    }
    else
    {

        if (!loadMedia())
        {
            printf("Failed to load media!\n");
        }
        else
        {

            SDL_BlitSurface(gHelloThere, NULL, gScreenSurface, NULL);

            SDL_UpdateWindowSurface(gameWindow);


            system("pause");
        }
    }


    close();

    return 0;
}