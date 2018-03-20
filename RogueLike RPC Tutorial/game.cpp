/*
 basic game:
 construct game object (window)
 initialize library and create window with parameters
 create a renderer to place items on teh windwo
 handle user events like quite
 if quitting clean up after yourself.
 */

#include "game.hpp"
#include "TextureManager.hpp"
#include "GameObject.hpp"

GameObject* player;


Game::Game()
{
}

Game::~Game()
{
}

void Game::init(const char *title, int xpos, int ypos, int width, int height, bool fullscreen)
{
    
    //added so we can decide if there is a full screen flag - need to review video #1 to fully understand 14:00
    int flags = 0;
    
    if(fullscreen)
        {
        flags = SDL_WINDOW_FULLSCREEN;
        }
    
    // initialize the system, then the game window then the renderer.
    
    if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
        {
        std::cout << "SDL Subsystems Initialized..." << std::endl;
        
        window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
        if (window) {
            std::cout << "Window Created" << std::endl;
        }
        
        renderer = SDL_CreateRenderer(window, -1, 0);
        if (renderer)
        {
            //set the Render draw color
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            
            //message to console the portion is complete
            std::cout << "Renderer Created" << std::endl;
        }
        
        // if all works return true else it returns false then stops the game loop in main while loop
        isRunning = true;
        } else
            {
            isRunning = false;
            }
    
    player = new GameObject("player.png", renderer);
}

void Game::handleEvents() {
    
    //create an event object
    SDL_Event event;
    //poll the event stack and get the address of the event
    SDL_PollEvent(&event);
    //create a switch for various types of events.
    switch (event.type) {
        case SDL_QUIT:
            isRunning = false;
            break;
            
        default:
            break;
    }
    
}

void Game::update() {
    
    //temporarily added a counter in the console window
    count++;
    player->Update();
    
    std::cout << count << std::endl;
}

void Game::render() {
    
    //clear the renderer
    SDL_RenderClear(renderer);
    player->Render();
    //present stuff to show
    SDL_RenderPresent(renderer);
}

void Game::clean() {
    
    //clean up renderer, window and clean quit SDL
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    std::cout << "Game Cleaned up, BYE!!" << std::endl;
    
}





