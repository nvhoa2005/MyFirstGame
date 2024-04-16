#ifndef _MAP__
#define _MAP__

#include "Defs.h"
#include "Base.h"

struct Map{
    int start_x;
    int start_y;

    int end_x;
    int end_y;

    int square[MAX_MAP_Y][MAX_MAP_X];
    string file_name;
};
class GameMap
{
private:
    Map gameMap;
    Base square[MAX_SQUARE];
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
