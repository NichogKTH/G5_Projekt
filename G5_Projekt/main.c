#include <stdio.h>
#include <SDL2/SDL.h>
#include <stdbool.h>

const int HEIGTH = 800, WIDTH = 800;
bool init();

SDL_Window* window = NULL;
SDL_Renderer* renderer = NULL;

int main(int argc, const char * argv[])
{
    SDL_Event e;
    bool running = true;
    if(init())
    {
        printf("Initialize successful.");
    }
    //Init media here
    while(running)
    {
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) {
                running = false;
            }
/*
            else if( e.type == SDL_KEYDOWN )
            {
                //Select surfaces based on key press
                switch( e.key.keysym.sym )
                {
                    case SDLK_UP:
                        possition.y -= 2;
                        flip = SDL_FLIP_NONE;
                        if(frame == 4)
                            frame = 5;
                        else
                            frame = 4;
                        break;
                    case SDLK_DOWN:
                        possition.y += 2;
                        flip = SDL_FLIP_NONE;
                        if(frame == 0)
                            frame = 1;
                        else
                            frame = 0;
                        break;
                    case SDLK_LEFT:
                        possition.x -= 2;
                        flip = SDL_FLIP_HORIZONTAL;
                        if(frame == 2)
                            frame = 3;
                        else
                            frame = 2;
                        break;
                    case SDLK_RIGHT:
                        possition.x += 2;
                        flip = SDL_FLIP_NONE;
                        if(frame == 2)
                            frame = 3;
                        else
                            frame = 2;
                        break;
                    default:
                        
                        break;
                }
            }
            */
    }
         
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderClear(renderer);
        //renderBackground();
        SDL_RenderPresent(renderer);
    }
    return 0;
}
/**
 Init code taken from Jonas Willén.
 */
bool init()
{
    bool test = true;
    SDL_Init(SDL_INIT_VIDEO);
    window = SDL_CreateWindow("Under production", SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED, HEIGTH, WIDTH, SDL_WINDOW_SHOWN);
    if(window == NULL)
    {
        printf("Could not create window. Error: %s ",SDL_GetError());
        test = false;
    }
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED| SDL_RENDERER_PRESENTVSYNC);
    if(renderer == NULL)
    {
        printf("Could not create renderer. Error: %s",SDL_GetError());
        test = false;
    }
    return test;
}
