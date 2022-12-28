#include "Game.h"
#include <iostream>
#include <SDL2/SDL.h>

Game::Game(/* args */)
{
    isRunning = false;
    std::cout << "Game constructor was called" << std::endl;
}

Game::~Game()
{
    std::cout << "Game destructor was called" << std::endl;
}

void Game::Initialize() {
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        std::cerr << "Error initializing SDL." << std::endl;
        return;
    }

    window = SDL_CreateWindow(
        NULL,
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        800,
        600,
        SDL_WINDOW_BORDERLESS
    );

    if (!window) {
        std::cerr << "Error creating SDL WINDOW" << std::endl;
        return;
    }

    renderer = SDL_CreateRenderer(window, -1, 0); // renderer to draws to

    if (!renderer) {
        std::cerr << "Error creating SDL Renderer" << std::endl;
        return;
    }

    isRunning = true;
}

void Game::ProcessInput() {
    SDL_Event sdlEvent;
    while (SDL_PollEvent(&sdlEvent)) {
        switch (sdlEvent.type) {
            case SDL_QUIT:
                isRunning = false;
                break;
            case SDL_KEYDOWN:
                if (sdlEvent.key.keysym.sym == SDLK_ESCAPE) {
                    isRunning = false;
                }
        }
    }
}

void Game::Run() {
    while (isRunning)
    {
        ProcessInput();
        Update();
        Render();
    }
}

void Game::Update() {
    // TODO: update game objects
}

void Game::Render() {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    // TODO: Render game objects

    SDL_RenderPresent(renderer);
}

void Game::Destroy() {
    // TODO: destroy allocated resources
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}