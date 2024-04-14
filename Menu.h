#ifndef _MENU__
#define _MENU__

#include "Player.h"
#include "Text.h"

class ShowMenu : public Player{
public:
    ShowMenu();
    ~ShowMenu();
    int showMenu(SDL_Renderer*, TTF_Font*, string, Mix_Chunk*);
    bool CheckMouseInOut(const int &x, const int &y, const int &a, const int &b);
    int showHowToPlay(SDL_Renderer*, TTF_Font*, string, Mix_Chunk*);
    int showMenuGameOver(SDL_Renderer*, TTF_Font*, string, Player, Mix_Chunk*);
};

#endif // _MENU__