#ifndef _TEXT__
#define _TEXT__

#include "Defs.h"

class Text
{
public:
    Text();
    ~Text();

    void RenderText(TTF_Font*, SDL_Renderer*, int x, int y);
    void Free();

    void SetColor(Uint8 red, Uint8 green, Uint8 blue);

    void SetText(const string &str){
        text = str;
    }
    string GetText() const{
        return text;
    }
private:
    string text;
    SDL_Color colorText;
    SDL_Texture* texture;
};


#endif // _TEXT__
