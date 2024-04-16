#ifndef _BASE__
#define _BASE__

#include "Defs.h"
class Base{
public:
    Base();
    ~Base();
    bool Load_image(string path, SDL_Renderer* screen);
    void Render(SDL_Renderer* des);
    void SetRect(const int&x, const int&y){
        rect.x = x, rect.y = y;
    }
    void logErrorAndExit(const char* msg, const char* error){
        SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_ERROR, "%s: %s", msg, error);
        SDL_Quit();
    }
    void Free();
protected:
    SDL_Rect rect;
    SDL_Texture* object;
};


#endif // _BASE__
