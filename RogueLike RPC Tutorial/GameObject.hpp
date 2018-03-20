#ifndef GameObject_hpp
#define GameObject_hpp

#include "game.hpp"
#include <stdio.h>

class GameObject {
    
public:
    GameObject(const char* texturesheet, SDL_Renderer* ren);
    ~GameObject();
    
    void Update();
    void Render();
    
private:
    int xpos;
    int ypos;
    
    SDL_Texture* objectTexture;
    SDL_Rect srcRect;
    SDL_Rect destRect;
    SDL_Renderer* renderer;
    
};

#endif /* GameObject_hpp */
