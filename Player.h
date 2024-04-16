#ifndef _PLAYER__H
#define _PLAYER__H

#include "Defs.h"
#include "Base.h"
#include "Map.h"

#define GRAVITY_SPEED 2
#define MAX_FALL_SPEED 15
#define PLAYER_SPEED 0.00003
#define MAX_PLAYER_SPEED 6
#define PLAYER_JUMP_VAL 13

class Player : public Base
{
public:
    Player();
    ~Player();

    bool Load_image(string path, SDL_Renderer* screen, int n);
    void Show(SDL_Renderer* des, int n);
    void Input(SDL_Event, SDL_Renderer*, Mix_Chunk*);
    void SetClips(int n);

    void MoveMap(Map& map_data);
    void WhileJump(Map& map_data, Mix_Chunk* sound[]);
    void CheckMap(Map& map_data, Mix_Chunk* sound[]);
    void SetMap(const int x, const int y){map_x = x; map_y = y;}

    int get_point(){
        return point;
    }
    void set_point(int other){
        point = other;
    }
    int get_record(){
        return record;
    }
    void set_record(int other){
        record = other;
    }
    void set_game_over(bool check){
        game_over = check;
    }
    bool get_game_over(){
        return game_over;
    }
    void reset(){
        frame = 0;
        x_add = 0;
        y_add = 0;
        x_now = 80;
        y_now = 80;
        jump = 0;
        map_x = 0;
        map_y = 0;
        tmp = 0;
        point = 0;
        game_over = false;
        width_frame = 0;
        height_frame = 0;
    }
private:
    double x_add;
    double y_add;

    double x_now;
    double y_now;

    int tmp;
    int point;
    int record;

    int width_frame;
    int height_frame;

    SDL_Rect frameMove[15];
    int jump;
    int frame;

    int map_x;
    int map_y;

    bool game_over;
};

#endif // _PLAYER__H
