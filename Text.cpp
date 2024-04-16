#include "Text.h"

Text::Text(){
    colorText.r = MAX_COLOR;
    colorText.g = MAX_COLOR;
    colorText.b = MAX_COLOR;
    texture = NULL;
}
Text::~Text(){

}

void Text::RenderText(TTF_Font* font, SDL_Renderer* screen, int x, int y)
{
    Free();
    
    SDL_Surface* text_surface = TTF_RenderText_Solid(font, text.c_str(), colorText);
    if(text_surface == nullptr){
        SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_ERROR, "Render text surface %s", TTF_GetError());
    }
    texture = SDL_CreateTextureFromSurface(screen, text_surface);
    if( texture == nullptr ) {
        SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_ERROR, "Create texture from text %s", SDL_GetError());
    }
    SDL_Rect dest = {x, y};
    SDL_FreeSurface(text_surface);
    SDL_QueryTexture(texture, NULL, NULL, &dest.w, &dest.h);
    SDL_RenderCopy(screen, texture, NULL, &dest);
}

void Text::Free()
{
    SDL_DestroyTexture(texture);
    texture = NULL;
}

void Text::SetColor(Uint8 red, Uint8 green, Uint8 blue)
{
    colorText.r = red;
    colorText.g = green;
    colorText.b = blue;
}
