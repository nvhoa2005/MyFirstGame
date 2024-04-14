#include "Base.h"

Base::Base(){
    rect.x = 0;
    rect.y = 0;
    rect.w = 0;
    rect.h = 0;
    p_object = NULL;
}
Base::~Base(){
    Free();
}

bool Base::Load_image(string path, SDL_Renderer* screen){
    SDL_Texture* new_texture = NULL;
    SDL_Surface* load_surface = IMG_Load(path.c_str());
    if(load_surface != NULL){
        SDL_SetColorKey(load_surface, SDL_TRUE, SDL_MapRGB(load_surface->format, COLOR_KEY_R, COLOR_KEY_G, COLOR_KEY_B));
        new_texture = SDL_CreateTextureFromSurface(screen, load_surface);
        if(new_texture != NULL){
            rect.h = load_surface->h;
            rect.w = load_surface->w;

        SDL_FreeSurface(load_surface);
        }
    }
    p_object = new_texture;
    return p_object != NULL;
}

void Base::Render(SDL_Renderer* des, const SDL_Rect* clip){
    SDL_Rect dest = {rect.x, rect.y, rect.w, rect.h};

    SDL_RenderCopy(des, p_object, clip, &dest);
}

void Base::Free(){
    if(p_object != NULL){
        SDL_DestroyTexture(p_object);
        p_object = NULL;
        rect.w = 0;
        rect.h = 0;
    }
}



