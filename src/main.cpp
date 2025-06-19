#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

#include "RenderWindow.hpp"
#include "Entity.hpp"

int main(int argc, char* argv[]) {
    if ( SDL_Init(SDL_INIT_VIDEO) > 0) {
        std::cout << "SDL_Init Has Failed. SDL_ERROR: " << SDL_GetError() << std::endl;
    }

    if ( !(IMG_Init(IMG_INIT_PNG))) {
        std::cout << "IMG_Init Has Failed. SDL_ERROR: " << IMG_GetError() << std::endl;
    }

    RenderWindow window("GAME v1.0", 1280, 720);

    SDL_Texture* grassTexture = window.loadTexture("res/gfx/grass.png");

    Entity entities[3] = {
        Entity(0, 0, grassTexture),
        Entity(16, 0, grassTexture),
        Entity(16, 0, grassTexture),
    };


    bool gameRunning = true;

    SDL_Event event;

    while (gameRunning){
        while (SDL_PollEvent(&event)){
            if (event.type == SDL_QUIT){
                gameRunning = false;
            }
        }

        window.clear();

        int i = 0;

        for (;;){
            window.render(entities[i]);
            i++;
            if (!(i <4)){
                break;
            }
        }

        window.display();
    }

    window.cleanUp();
    SDL_Quit();

    return 0;
}