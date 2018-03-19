//
//  game.hpp
//  RogueLike RPC Tutorial
//
//  Created by Developer on 3/18/18.
//  Copyright © 2018 Mark Wooding. All rights reserved.
//

#ifndef game_hpp
#define game_hpp

#include <stdio.h>
#include <iostream>

#include <SDL2/SDL.h>
#include "SDL2_Image/SDL_Image.h"

class Game {

public:
    Game();
    ~Game();
    
    void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
    void handleEvents();
    void update();
    void render();
    void clean();
    
    bool running() {return isRunning; }
    
private:
    
    int count = 0;
    bool isRunning;
    SDL_Window *window;
    SDL_Renderer *renderer;
    
};

#endif /* game_hpp */
