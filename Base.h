#ifndef _BASE__
#define _BASE__

#include "Defs.h"
class Base{
public:
    Base();
    ~Base();
    bool Load_image(string path, SDL_Renderer* screen);
    void Render(SDL_Renderer* des, const SDL_Rect* clip = NULL);
    void SetRect(const int&x, const int&y){
        rect.x = x, rect.y = y;
    }
    SDL_Rect GetRect(){
        return rect;
    }
    SDL_Texture* GetObject(){
        return object;
    }
    void Free();
protected:
    SDL_Texture* object;
    SDL_Rect rect;
};


#endif // _BASE__
