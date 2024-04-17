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
        g_background.logErrorAndExit("SDL_Init", SDL_GetError());
        return false;
    }

    g_window = SDL_CreateWindow("FLAPPY BIRD", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

    if(g_window == NULL){
        g_background.logErrorAndExit("CreateWindow", SDL_GetError());
        success = false;
    }
    else{
        g_screen = SDL_CreateRenderer(g_window, -1, SDL_RENDERER_ACCELERATED);
        if(g_screen == NULL){
            g_background.logErrorAndExit("CreateRenderer", SDL_GetError());
            success = false;
        }
        else{
            if (!IMG_Init(IMG_INIT_PNG || IMG_INIT_JPG)){
                g_background.logErrorAndExit("SDL_image error:", IMG_GetError());
                success = false;
            }
        }
    }
    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
    SDL_RenderSetLogicalSize(g_screen, SCREEN_WIDTH, SCREEN_HEIGHT);

    if(TTF_Init() == -1){
        g_background.logErrorAndExit(
                     "SDL_TTF could not initialize! SDL_TTF Error: ", TTF_GetError());
        success = false;
    }
    font = TTF_OpenFont("font//pixel.ttf", 25);
    if(font == NULL){
        g_background.logErrorAndExit(
                     "Could not open font ! SDL_TTF Error: ", TTF_GetError());
        success = false;
    }
    menu = TTF_OpenFont("font//pixel.ttf", 45);
    if(menu == NULL){
        g_background.logErrorAndExit(
                     "Could not open font ! SDL_TTF Error: ", TTF_GetError());
        success = false;
    }

    if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 ) {
        g_background.logErrorAndExit(
                     "SDL_MIXER could not initialize! SDL_MIXER Error: ", Mix_GetError());
        return false;
    }

    g_sound[0] = Mix_LoadWAV("sound//point.wav");
    g_sound[1] = Mix_LoadWAV("sound//die.wav");
    g_sound[2] = Mix_LoadWAV("sound//hit.wav");
    g_sound[3] = Mix_LoadWAV("sound//flap.wav");
    g_sound[4] = Mix_LoadWAV("sound//click.wav");

    for(int i = 0; i < MAX_SOUND; i++){
        if(g_sound[i] == NULL){
            g_background.logErrorAndExit(
                       "Could not load sound! SDL_mixer Error: %s", Mix_GetError());
            return false;
        }
    }
    
    g_music = Mix_LoadMUS("sound//Nhacnen.mp3");
    if (g_music == nullptr) {
        g_background.logErrorAndExit(
                        "Could not load music! SDL_mixer Error: %s", Mix_GetError());
        return false;
    }

    bool load = g_background.Load_image("img//background.jpg", g_screen);
    if(load == false){
        g_background.logErrorAndExit(
                           "Could not load g_background! SDL_Image Error: %s", IMG_GetError());
        return false;
    }
    return success;
}

void close(){
    g_background.Free();
    SDL_DestroyRenderer(g_screen);
    SDL_DestroyWindow(g_window);
    g_screen = NULL;
    g_window = NULL;

    TTF_CloseFont(font);
    TTF_CloseFont(menu);
    font = NULL;
    menu  = NULL;

    Mix_FreeMusic(g_music);
    g_music = NULL;
    for(int i = 0; i < MAX_SOUND; i++){
        Mix_FreeChunk(g_sound[i]);
        g_sound[i] = NULL;
    }

    Mix_Quit();
    TTF_Quit();
    IMG_Quit();
    SDL_Quit();
}
using namespace std;
int main(int argc, char* argv[])
{
    if(InitData() == false){
        cerr << "INIT_ERROR" << endl;
        return -1;
    }

    GameMap game_map;
    string path = "map//map02.txt";
    game_map.LoadMap(path);
    game_map.LoadSquare(g_screen);

    Player player;

    Text point_game;
    point_game.SetColor(225, 225, 225);

    ShowMenu show_menu;
    bool is_quit = false;
    int choose_char = 0;;
    Mix_PlayMusic(g_music, -1);
    int choose_menu = show_menu.showMenu(g_screen, menu, "img//backgroundstart.jpg", g_sound[4]);
    if(choose_menu == EXIT_GAME){
        Mix_CloseAudio();
        cout << "EXIT" << endl;
        is_quit = true;
    }
    else if(choose_menu == START_GAME){
        choose_char = show_menu.chooseChar(g_screen, menu, "img//backgroundchoosechar.jpg", g_sound[4]);
        if(choose_char == CHAR_1){
            player.Load_image("img//mainbird1.png", g_screen, choose_char);
            player.SetClips(CHAR_1);
        }
        else if(choose_char == CHAR_2){
            player.Load_image("img//mainbird2.png", g_screen, choose_char);
            player.SetClips(CHAR_2);
        }
        else if(choose_char == CHAR_3){
            player.Load_image("img//mainbird3.png", g_screen, choose_char);
            player.SetClips(CHAR_3);
        }
        else if(choose_char == CHAR_4){
            player.Load_image("img//mainbird4.png", g_screen, choose_char);
            player.SetClips(CHAR_4);
        }
        else{
            Mix_CloseAudio();
            cout << "EXIT" << endl;
            is_quit = true;
        }
    }
    bool check = player.get_game_over();
    bool pause_game = false;
    bool continue_game = false;
    while(!is_quit){
        int time = SDL_GetTicks();
        Mix_PauseMusic();
        while(SDL_PollEvent(&g_event) != 0){
            if(g_event.type == SDL_QUIT){
                is_quit = true;
                close();
                return 0;
            }

            player.Input(g_event, g_screen, g_sound[3], pause_game);
        }
        if(pause_game == true){
            int game_paused = show_menu.menuPaused(g_screen, menu, "img//backgroundgamepaused.jpg", g_sound[4], pause_game);
            if(game_paused == EXIT_GAME){
                is_quit = true;
                close();
                return 0;
            }
            else continue_game = true;
        }
        SDL_SetRenderDrawColor(g_screen, MAX_COLOR, MAX_COLOR, MAX_COLOR, MAX_COLOR);
        SDL_RenderClear(g_screen);

        g_background.Render(g_screen);
        Map map_data = game_map.getMap();

        player.SetMap(map_data.start_x, map_data.start_y);
        player.WhileJump(map_data, g_sound);
        player.Show(g_screen, choose_char);

        game_map.SetMap(map_data);
        game_map.DrawMap(g_screen);

        string str_point = "Point: ";
        string point_val = to_string(player.get_point());
        str_point += point_val;

        point_game.SetText(str_point);
        point_game.RenderText(font, g_screen, 60, 15);

        SDL_RenderPresent(g_screen);
        if(continue_game){
            Mix_ResumeMusic();
            Text count_down[4];
            for(int i = 3; i >= 1; i--){
                count_down[i].SetColor(MAX_COLOR, MAX_COLOR, MIN_COLOR);
                count_down[i].SetText(to_string(i));
                count_down[i].RenderText(menu, g_screen, 1000-100*i, 100);
                SDL_RenderPresent(g_screen);
                SDL_Delay(700);
            }
            count_down[0].SetColor(MAX_COLOR, MIN_COLOR, MIN_COLOR);
            count_down[0].SetText("CONTINUE");
            count_down[0].RenderText(menu, g_screen, 800, 200);
            SDL_RenderPresent(g_screen);
            SDL_Delay(500);
            continue_game = false;
        }

        check = player.get_game_over();
        if(check == true){
            Mix_ResumeMusic();
            int choose_game_over = show_menu.showMenuGameOver(g_screen, menu, "img//backgroundGameOver.jpg", player, g_sound[4]);
            if(choose_game_over == EXIT_GAME){
                Mix_CloseAudio();
                cout << "EXIT" << endl;
                is_quit = true;
                close();
                return 0;
            }
            else if(choose_game_over == PLAY_AGAIN){
                player.reset();
                continue;
            }
            else if(choose_game_over == CHOOSE_CHAR){
                player.reset();
                choose_char = show_menu.chooseChar(g_screen, menu, "img//backgroundchoosechar.jpg", g_sound[4]);
                if(choose_char == CHAR_1){
                    player.Load_image("img//mainbird1.png", g_screen, choose_char);
                    player.SetClips(CHAR_1);
                    continue;
                }
                else if(choose_char == CHAR_2){
                    player.Load_image("img//mainbird2.png", g_screen, choose_char);
                    player.SetClips(CHAR_2);
                    continue;
                }
                else if(choose_char == CHAR_3){
                    player.Load_image("img//mainbird3.png", g_screen, choose_char);
                    player.SetClips(CHAR_3);
                    continue;
                }
                else if(choose_char == CHAR_4){
                    player.Load_image("img//mainbird4.png", g_screen, choose_char);
                    player.SetClips(CHAR_4);
                    continue;
                }
                else{
                    Mix_CloseAudio();
                    cout << "EXIT" << endl;
                    is_quit = true;
                    close();
                    return 0;
                }
            }
        }

        int one_loop_time = SDL_GetTicks() - time;
        int one_frame_time = 1000/FRAME_PER_SECOND; //ms
        if(one_loop_time < one_frame_time){
            int delay_time = one_frame_time - one_loop_time;
            SDL_Delay(delay_time);
        }

    }
    close();
    return 0;
}

