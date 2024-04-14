#ifndef _BASE__
#define _BASE__

#include "Function.h"

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
        return p_object;
    }
    void Free();
protected:
    SDL_Texture* p_object;
    SDL_Rect rect;
};


#endif // _BASE__
