#include "Defs.h"
#include "Base.h"
#include "Map.h"
#include "Player.h"
#include "Time.h"
#include "Text.h"
#include "Menu.h"
Base g_background;
bool InitData(){
    bool success = true;
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0){
        SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_ERROR, "%s: %s", "SDL_Init", SDL_GetError);
        return false;
    }

    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");

    g_window = SDL_CreateWindow("FLAPPY BIRD", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if(g_window == NULL){
        success = false;
    }
    else{
        g_screen = SDL_CreateRenderer(g_window, -1, SDL_RENDERER_ACCELERATED);
        if(g_screen == NULL) success = NULL;
        else{
            SDL_SetRenderDrawColor(g_screen, MAX_COLOR, MAX_COLOR, MAX_COLOR, MAX_COLOR);
            int imgFlags = IMG_INIT_PNG;
            if(!(IMG_Init(imgFlags) && imgFlags)) success = false;

        }

        if(TTF_Init() == -1){
            cerr << "SDL_TTF could not initialize! SDL_TTF Error: " << TTF_GetError << endl;
            success = false;
        }
        font = TTF_OpenFont("font//pixel.ttf", 25);
        if(font == NULL){
            cerr << "Could not open! SDL_TTF Error: " << TTF_GetError << endl;
            success = false;
        }
        menu = TTF_OpenFont("font//pixel.ttf", 45);
        if(menu == NULL){
            cerr << "Could not open! SDL_TTF Error: " << TTF_GetError << endl;
            success = false;
        }
    }

    if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 ) {
        cerr << "SDL_MIXER could not initialize! SDL_MIXER Error: " << Mix_GetError << endl;
        return false;
    }

    g_sound[0] = Mix_LoadWAV("sound//point.wav");
    g_sound[1] = Mix_LoadWAV("sound//die.wav");
    g_sound[2] = Mix_LoadWAV("sound//hit.wav");
    g_sound[3] = Mix_LoadWAV("sound//flap.wav");
    g_sound[4] = Mix_LoadWAV("sound//click.wav");

    for(int i = 0; i < MAX_SOUND; i++){
        if(g_sound[i] == NULL){
            SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_ERROR,
                       "Could not load sound! SDL_mixer Error: %s", Mix_GetError());
            return false;
        }
    }

    return success;
}
bool LoadBackground(){
    bool ret = g_background.Load_image("img//background.jpg", g_screen);
    if(ret == false){
        cerr << "Cannot load background" << endl;
        return false;
    }
    return true;
}
void close(){
    g_background.Free();
    SDL_DestroyRenderer(g_screen);
    g_screen = NULL;

    SDL_DestroyWindow(g_window);
    g_window = NULL;

    TTF_CloseFont(font);
    font = NULL;
    TTF_CloseFont(menu);
    menu  = NULL;

    for(int i = 0; i < MAX_SOUND; i++){
        Mix_FreeChunk(g_sound[i]);
        g_sound[i] = NULL;
    }

    IMG_Quit();
    SDL_Quit();
    TTF_Quit();
    Mix_Quit();
}
using namespace std;
int main(int argc, char* argv[])
{
    Time fps;

    if(InitData() == false){
        cerr << "INIT_ERROR" << endl;
        return -1;
    }
    if(LoadBackground() == false) return -1;

    GameMap game_map;
    string path = "map//map02.txt";
    game_map.LoadMap(path);
    game_map.LoadSquare(g_screen);

    Player player;
    player.Load_image("img//mainbird.png", g_screen);
    player.SetClips();

    Text time_game;
    time_game.SetColor(225, 225, 225);

    Text point_game;
    point_game.SetColor(225, 225, 225);

    ShowMenu show_menu;
    bool is_quit = false;

    int ret_menu = show_menu.showMenu(g_screen, menu, "img//background.jpg", g_sound[4]);
    if(ret_menu == 2){
        cout << "EXIT" << endl;
        is_quit = true;
    }
    bool check = player.get_game_over();
    while(!is_quit){
        fps.start();
        while(SDL_PollEvent(&g_event) != 0){
            if(g_event.type == SDL_QUIT){
                is_quit = true;
            }

            player.Input(g_event, g_screen, g_sound[3]);
        }
        SDL_SetRenderDrawColor(g_screen, MAX_COLOR, MAX_COLOR, MAX_COLOR, MAX_COLOR);
        SDL_RenderClear(g_screen);

        g_background.Render(g_screen, NULL);
        Map map_data = game_map.getMap();

        player.SetMap(map_data.start_x, map_data.start_y);
        player.WhileJump(map_data, g_sound);
        player.Show(g_screen);

        game_map.SetMap(map_data);
        game_map.DrawMap(g_screen);

        string str_time = "Time: ";
        Uint32 time_val = SDL_GetTicks() / 1000; //ms;
        string str_val = to_string(time_val);
        str_time += str_val;

        string str_point = "Point: ";
        string point_val = to_string(player.get_point());
        str_point += point_val;

        time_game.SetText(str_time);
        time_game.RenderText(font, g_screen, SCREEN_WIDTH-160, 15);

        point_game.SetText(str_point);
        point_game.RenderText(font, g_screen, 60, 15);

        SDL_RenderPresent(g_screen);

        check = player.get_game_over();
        if(check == true){
            int ret_menu = show_menu.showMenuGameOver(g_screen, menu, "img//backgroundGameOver.jpg", player, g_sound[4]);
            if(ret_menu == 2){
                cout << "EXIT" << endl;
                is_quit = true;
            }
            else if(ret_menu == PLAY_AGAIN){
                player.reset();
            }
        }

        int real_time = fps.get_ticks();
        int one_frame_time = 1000/FRAME_PER_SECOND; //ms

        if(real_time < one_frame_time){
            int delay_time = one_frame_time - real_time;
            SDL_Delay(delay_time);
        }
    }
    close();
    return 0;
}

