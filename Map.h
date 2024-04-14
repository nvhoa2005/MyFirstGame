#ifndef _MAP__
#define _MAP__

#include "Function.h"
#include "Base.h"

struct Map{
    int start_x;
    int start_y;

    int max_x;
    int max_y;

    int square[MAXMAPY][MAXMAPX];
    string file_name;
};

class Square : public Base
{
public:
    Square(){

    }
    ~Square(){

    }
};

class GameMap
{
private:
    Map gameMap;
    Square square[MAX_SQUARE];
public:
    GameMap(){
    }
    ~GameMap(){
    }
    Map getMap(){
        return gameMap;
    }
    void SetMap(Map& map_data){
        gameMap = map_data;
    }
    void LoadMap(string &path);
    void LoadSquare(SDL_Renderer* scr);
    void DrawMap(SDL_Renderer* scr);
};

#endif // _MAP__
