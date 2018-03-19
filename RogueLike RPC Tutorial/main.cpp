// Following "Let's Make Games" youtube series RogueLike RPG
//  main.cpp
//  RogueLike RPC Tutorial
//
//  Created by Developer on 3/18/18.
//  Copyright © 2018 Mark Wooding. All rights reserved.
//

#include <iostream>
#include <SDL2/SDL.h>
#include "game.hpp"

//create a game variable (pointer) set to null
Game *game = nullptr;

int main() {

    //will cap the framrate, need a few variables for calculations
    const int FPS = 60;
    const int FRAME_DELAY = 1000 / FPS;
    
    Uint32 frameStart;
    int frameTime;
    
    
    //create a game object
    game = new Game();
    
    //added some constants for the window height and width may remove them later.
    const int WINDOW_WIDTH = 800;
    const int WINDOW_HEIGHT = 600;
   
    //initialize game with arguments
    game->init("RogueLike RPG Engine", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WINDOW_WIDTH, WINDOW_HEIGHT, false);
    
    while ( game->running() ) {
        
        //gets the initial number for calculations before the actual gameloop begins
        frameStart = SDL_GetTicks();
        
        game->handleEvents();
        game->update();
        game->render();
        
        //after the game loops, will calculate the time of the loop activities
        frameTime = SDL_GetTicks() - frameStart;
        
        //check to see how long the loop activites take and delay
        if (FRAME_DELAY > frameTime){
            SDL_Delay(FRAME_DELAY - frameTime);
        }
        
    }
    
    //when no longer running will go here and close down.
    game->clean();
    
    return 0;
}

