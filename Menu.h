#ifndef _MENU__
#define _MENU__

#include "Player.h"
#include "Text.h"

class ShowMenu : public Base{
public:
    ShowMenu();
    ~ShowMenu();
    int showMenu(SDL_Renderer*, TTF_Font*, string, Mix_Chunk*);
    bool CheckMouse(const int &x, const int &y, const int &a, const int &b);
    int showHowToPlay(SDL_Renderer*, TTF_Font*, string, Mix_Chunk*);
    int showMenuGameOver(SDL_Renderer*, TTF_Font*, string, Player, Mix_Chunk*);
    int chooseChar(SDL_Renderer*, TTF_Font*, string, Mix_Chunk*);
    int menuPaused(SDL_Renderer*, TTF_Font*, string, Mix_Chunk*, bool&);
    int menuWinGame(SDL_Renderer*, TTF_Font*, string, Mix_Chunk*, bool&);
};

#endif // _MENU__
