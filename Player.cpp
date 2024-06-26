#include "Player.h"

Player::Player()
{
    frame = 0;
    x_now = 80;
    y_now = 80;
    x_add = 0;
    y_add = 0;
    width_frame = 0;
    height_frame = 0;
    jump = 0;
    map_x = 0;
    map_y = 0;
    tmp = 0;
    game_over = false;
    point = 0;
    record = 0;
}

Player::~Player(){

}

bool Player::Load_image(string path, SDL_Renderer* screen, int n)
{
    bool load = Base::Load_image(path, screen);

    if(load == true)
    {   
        if(n == CHAR_1){
            width_frame = rect.w/5;
            height_frame = rect.h/3;
        }
        else{
            width_frame = rect.w/3;
            height_frame = rect.h/3;
        }
    }
    return load;
}

void Player::SetClips(int n){
    if(n == CHAR_1){
        for(int i = 0; i < 5; i++){
            frameMove[i].x = i*width_frame;
            frameMove[i].y = 0;
            frameMove[i].w = width_frame;
            frameMove[i].h = height_frame;
        }
        for(int i = 5; i < 10; i++){
            frameMove[i].x = (i%5)*width_frame;
            frameMove[i].y = height_frame;
            frameMove[i].w = width_frame;
            frameMove[i].h = height_frame;
        }
        for(int i = 10; i < 14; i++){
            frameMove[i].x = (i%5)*width_frame;
            frameMove[i].y = 2*height_frame;
            frameMove[i].w = width_frame;
            frameMove[i].h = height_frame;
        }
    }
    else{
        for(int i = 0; i < 3; i++){
            frameMove[i].x = i*width_frame;
            frameMove[i].y = 0;
            frameMove[i].w = width_frame;
            frameMove[i].h = height_frame;
        }
        for(int i = 3; i < 6; i++){
            frameMove[i].x = (i%3)*width_frame;
            frameMove[i].y = height_frame;
            frameMove[i].w = width_frame;
            frameMove[i].h = height_frame;
        }
        for(int i = 6; i < 9; i++){
            frameMove[i].x = (i%3)*width_frame;
            frameMove[i].y = 2*height_frame;
            frameMove[i].w = width_frame;
            frameMove[i].h = height_frame;
        }
    }
}

void Player::Show(SDL_Renderer* des, int n){
    string path = "img//mainbird" + to_string(n) + ".png";
    Load_image(path, des, n);
    if(n == CHAR_1){
        frame++;
        if(frame >= 14) frame = 0;
    }
    else{
        frame++;
        if(frame >= 9) frame = 0;
    }
    rect.x = x_now - map_x;
    rect.y = y_now - map_y;

    SDL_Rect* current_frame = &frameMove[frame];

    SDL_Rect dest = {rect.x, rect.y, width_frame, height_frame};

    SDL_RenderCopy(des, object, current_frame, &dest);
}

void Player::Input(SDL_Event events, SDL_Renderer* screen, Mix_Chunk *sound, bool &pause){
    if(events.type == SDL_KEYDOWN){
        if(events.key.keysym.sym == SDLK_SPACE || events.key.keysym.sym == SDLK_UP){
            jump = 1;
            Mix_PlayChannel( -1, sound, 0 );
        }
        if(events.key.keysym.sym == SDLK_ESCAPE){
            pause = true;
        }
    }
    else if(events.type == SDL_KEYUP){
        jump = 0;
    }
}

void Player::WhileJump(Map& map_data, Mix_Chunk* sound[], bool& win){

    x_add = 0;
    y_add += GRAVITY_SPEED;

    if(y_add >= MAX_FALL_SPEED){
        y_add = MAX_FALL_SPEED;
    }

    while(true){
        x_add += PLAYER_SPEED;
        if(x_add > MAX_PLAYER_SPEED) break;
        if(jump == 1){
            y_add = -PLAYER_JUMP_VAL;
        }
    }

    CheckMap(map_data, sound, win);
    MoveMap(map_data);
}

void Player::MoveMap(Map& map_data)
{
    map_data.start_x = x_now - (SCREEN_WIDTH/3);
    if(map_data.start_x <= 0){
        map_data.start_x = 0;
    }
    else if(map_data.start_x + SCREEN_WIDTH >= map_data.end_x){
        map_data.start_x = map_data.end_x - SCREEN_WIDTH;
    }
}

void Player::CheckMap(Map& map_data, Mix_Chunk* sound[], bool& win)
{
    int x1 = 0;
    int x2 = 0;

    int y1 = 0;
    int y2 = 0;

    x1 = (x_now)/SQUARE_SIZE;
    x2 = (x_now + width_frame)/SQUARE_SIZE;

    y1 = (y_now)/SQUARE_SIZE;
    y2 = (y_now + height_frame)/SQUARE_SIZE;

    for(int i = 1; i < MAX_MAP_Y-1; i++){
        if(map_data.square[i][x2]){
            tmp++;
            if(tmp >= 10){
                Mix_PlayChannel( -1, sound[0], 0 );
                point++;
                set_point(point);
                record = max(record, point);
                set_record(record);
                tmp = 0;
            }
            break;
        }
    }

    if(map_data.square[y1][x2] != BLANK_SQUARE || map_data.square[y2][x2] != BLANK_SQUARE ||
                    map_data.square[y1][x1] != BLANK_SQUARE || map_data.square[y2][x1] != BLANK_SQUARE){
        set_game_over(true);
        Mix_PlayChannel( -1, sound[2], 0 );
        Mix_PlayChannel( -1, sound[1], 0 );
    }

    if(get_game_over()){
        set_point(point--);
        set_record(record--);
    }

    x_now += x_add;
    y_now += y_add;

    if(x_now >= MAX_MAP_X*SQUARE_SIZE){
        win = true;
    }
}
