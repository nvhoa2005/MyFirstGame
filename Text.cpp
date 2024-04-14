#include "Text.h"

Text::Text(){
    colorText.r = MAX_COLOR;
    colorText.g = MAX_COLOR;
    colorText.b = MAX_COLOR;
    texture = NULL;
}
Text::~Text(){

}

bool Text::LoadText(TTF_Font* font, SDL_Renderer* screen)
{
    SDL_Surface* text_surface = TTF_RenderText_Solid(font, str_add.c_str(), colorText);
    if(text_surface)
    {
        texture = SDL_CreateTextureFromSurface(screen, text_surface);
        width = text_surface->w;
        height = text_surface->h;

        SDL_FreeSurface(text_surface);
    }

    return texture != NULL;
}

void Text::Free()
{
    if(texture != NULL)
    {
        SDL_DestroyTexture(texture);
        texture = NULL;
    }
}

void Text::SetColor(Uint8 red, Uint8 green, Uint8 blue)
{
    colorText.r = red;
    colorText.g = green;
    colorText.b = blue;
}

void Text::RenderText(SDL_Renderer* screen, int x, int y, SDL_Rect* clip, double angle, SDL_Point* center, SDL_RendererFlip flip){
    SDL_Rect renderquad = {x, y, width, height};
    if(clip != NULL)
    {
        renderquad.w = clip->w;
        renderquad.h = clip->h;
    }

    SDL_RenderCopyEx(screen, texture, clip, &renderquad, angle, center, flip);
}
