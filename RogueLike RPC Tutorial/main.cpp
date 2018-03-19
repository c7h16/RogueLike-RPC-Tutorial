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

//create a game object
    game = new Game();
    
    //added some constants for the window height and width may remove them later.
    const int WINDOW_WIDTH = 800;
    const int WINDOW_HEIGHT = 600;
   
    //initialize game with arguments
    game->init("RogueLike RPG Engine", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WINDOW_WIDTH, WINDOW_HEIGHT, true);
    
    while ( game->running() ) {
        game->handleEvents();
        game->update();
        game->render();
    }
    
    //when no longer running will go here and close down.
    game->clean();
    
    return 0;
}

