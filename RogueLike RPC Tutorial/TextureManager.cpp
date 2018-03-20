//
//  TextureManager.cpp
//  RogueLike RPC Tutorial
//
//  Created by Developer on 3/20/18.
//  Copyright © 2018 Mark Wooding. All rights reserved.
//

#include "TextureManager.hpp"

SDL_Texture* TextureManager::LoadTexture(const char *texture, SDL_Renderer *ren)
{
    SDL_Surface* tempSurface = IMG_Load(texture);
    SDL_Texture* tex = SDL_CreateTextureFromSurface(ren, tempSurface);
    SDL_FreeSurface(tempSurface);
    
    return tex;
}
