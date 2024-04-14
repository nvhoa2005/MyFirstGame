#ifndef _TEXT__
#define _TEXT__

#include "Function.h"

class Text
{
public:
    Text();
    ~Text();

    void RenderText(TTF_Font*, SDL_Renderer*, int x, int y);
    void Free();

    void SetColor(Uint8 red, Uint8 green, Uint8 blue);

    int GetWidth() const{
        return width;
    }
    int GetHeight() const{
        return height;
    }
    void SetText(const string &text){
        str_add = text;
    }
    string GetText() const{
        return str_add;
    }
private:
    string str_add;
    SDL_Color colorText;
    SDL_Texture* texture;
    int width;
    int height;
};


#endif // _TEXT__
