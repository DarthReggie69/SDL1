#include <iostream>
#include <SDL.h>






bool init();


bool loadMedia();


void close();


SDL_Window* gWindow = NULL;


SDL_Surface* gScreenSurface = NULL;


SDL_Surface* gHelloWorld = NULL;

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

        gWindow = SDL_CreateWindow("Mood Killers ", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1280, 720, SDL_WINDOW_SHOWN);
        if (gWindow == NULL)
        {
            printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
            success = false;
        }
        else
        {

            gScreenSurface = SDL_GetWindowSurface(gWindow);
        }
    }

    return success;
}

bool loadMedia()
{

    bool success = true;


    gHelloWorld = SDL_LoadBMP("Pictures/background.bmp");
    if (gHelloWorld == NULL)
    {
        printf("Unable to load image %s! SDL Error: %s\n", "Pictures/background.bmp", SDL_GetError());
        success = false;
    }

    return success;
}

void close()
{

    SDL_FreeSurface(gHelloWorld);
    gHelloWorld = NULL;


    SDL_DestroyWindow(gWindow);
    gWindow = NULL;


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

            SDL_BlitSurface(gHelloWorld, NULL, gScreenSurface, NULL);

            SDL_UpdateWindowSurface(gWindow);


            system("pause");
        }
    }


    close();

    return 0;
}