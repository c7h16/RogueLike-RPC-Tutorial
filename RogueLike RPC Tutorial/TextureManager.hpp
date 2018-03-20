//
//  TextureManager.hpp
//  RogueLike RPC Tutorial
//
//  Created by Developer on 3/20/18.
//  Copyright © 2018 Mark Wooding. All rights reserved.
//

#ifndef TextureManager_hpp
#define TextureManager_hpp

#include <stdio.h>
#include "game.hpp"

class TextureManager
{
public:
    static SDL_Texture* LoadTexture(const char* fileName, SDL_Renderer* ren);
    
};

#endif /* TextureManager_hpp */
