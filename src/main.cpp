#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <vector>

#include "RenderWindow.hpp"
#include "Entity.hpp"
#include "Utils.hpp"
#include "Math.hpp"

int main(int argc, char *argv[])
{
    if (SDL_Init(SDL_INIT_VIDEO) > 0)
    {
        std::cout << "SDL_Init Has Failed. SDL_ERROR: " << SDL_GetError() << std::endl;
    }

    if (!(IMG_Init(IMG_INIT_PNG)))
    {
        std::cout << "IMG_Init Has Failed. SDL_ERROR: " << IMG_GetError() << std::endl;
    }

    RenderWindow window("GAME v1.0", 1280, 720);

    SDL_Texture *grassTexture = window.loadTexture("res/gfx/grass.png");


    std::vector<Entity> entitiees = {
        Entity(Vector2f(0,0), grassTexture),
    };

    {
        Entity anotherGrass0(Vector2f(50, 50), grassTexture);
        Entity anotherGrass1(Vector2f(100, 50), grassTexture);
        Entity anotherGrass2(Vector2f(150, 50), grassTexture);

        entitiees.push_back(anotherGrass0);
        entitiees.push_back(anotherGrass1);
        entitiees.push_back(anotherGrass2);
    }

    bool gameRunning = true;

    SDL_Event event;

    const float timeStep = 0.01f;
    float accumulator = 0.0f;
    float currentTime = utils::hireTimeInSeconds();

    while (gameRunning)
    {

        int startTicks = SDL_GetTicks();

        float newTime = utils::hireTimeInSeconds();
        float frameTime = newTime - currentTime;

        currentTime = newTime;

        accumulator += frameTime;

        while (accumulator >= timeStep)
        {
            while (SDL_PollEvent(&event))
            {
                if (event.type == SDL_QUIT)
                {
                    gameRunning = false;
                }
            }

            accumulator -= timeStep;

        }

        const float alpha = accumulator / timeStep; //50%?

        window.clear();

        for (Entity &e : entitiees)
        {
            window.render(e);
        }

        window.display();

        int frameTicks = SDL_GetTicks () - startTicks;

        if(frameTicks < 1000 / window.getRefreshRate()){
            SDL_Delay(window.getRefreshRate() - frameTicks);
        }

    }

    window.cleanUp();
    SDL_Quit();

    return 0;
}