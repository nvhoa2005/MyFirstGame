#include "Menu.h"
ShowMenu::ShowMenu(){

}

ShowMenu::~ShowMenu(){

}

bool ShowMenu::CheckMouse(const int &x, const int &y, const int& a, const int&b)
{
    if(x >= a && x <= a + WIDTH_TEXT && y >= b && y <= b + HEIGHT_TEXT){
        return true;
    }
    return false;
}

int ShowMenu::showHowToPlay(SDL_Renderer* des, TTF_Font* font, string path, Mix_Chunk* sound){
    Base::Free();
    
    bool load = Base::Load_image(path, des);
    if(load == false){
        cerr << "Could not open ShowHowToPlay" << endl;
        return EXIT_GAME;
    }

    Text menuText[MENU+5];
    string s1 = "PLAY GAME";
    string s2 = "HOW TO PLAY:";
    string s3 = "EXIT";
    menuText[0].SetColor(MAX_COLOR, MAX_COLOR, MAX_COLOR);
    menuText[0].SetText(s1);
    menuText[1].SetColor(MAX_COLOR, 82, 6);
    menuText[1].SetText(s2);
    menuText[2].SetColor(MAX_COLOR, MAX_COLOR, MAX_COLOR);
    menuText[2].SetText(s3);
    bool check[MENU] = {0, 0, 0};
    int x = 0, y = 0;

    SDL_Event event;
    while(true){
        SDL_RenderClear(des);
        Base::Render(des);
        menuText[0].RenderText(font, des, 200, 390);
        menuText[1].RenderText(font, des, 50, 150);
        menuText[2].RenderText(font, des, 200, 450);

        while(SDL_PollEvent(&event)){
            switch(event.type){
                case SDL_QUIT:
                    return EXIT_GAME;
                case SDL_MOUSEMOTION:
                    x = event.motion.x;
                    y = event.motion.y;

                    if(CheckMouse(x, y, 200, 390)){
                        check[0] = true;
                        menuText[0].SetColor(MAX_COLOR, MIN_COLOR, MIN_COLOR);
                    }
                    else{
                        check[0] = false;
                        menuText[0].SetColor(MAX_COLOR, MAX_COLOR, MAX_COLOR);
                    }

                    if(CheckMouse(x, y, 200, 450)){
                        check[2] = true;
                        menuText[2].SetColor(MAX_COLOR, MIN_COLOR, MIN_COLOR);
                    }
                    else{
                        check[2] = false;
                        menuText[2].SetColor(MAX_COLOR, MAX_COLOR, MAX_COLOR);
                    }
                    break;
                case SDL_MOUSEBUTTONDOWN:
                    {
                        Mix_PlayChannel( -1, sound, 0 );
                        x = event.button.x;
                        y = event.button.y;

                        if(CheckMouse(x, y, 200, 390)){
                            return START_GAME;
                        }
                        if(CheckMouse(x, y, 200, 450)){
                            return EXIT_GAME;
                        }

                    }
                    break;
                case SDL_KEYDOWN:
                    if(event.key.keysym.sym == SDLK_ESCAPE){
                        return EXIT_GAME;
                    }
                default:
                    break;
            }

        }
        SDL_RenderPresent(des);
    }
    for(int i = 0; i < MENU; i++){
        menuText[i].Free();
    }
    SDL_DestroyRenderer(des);
    return START_GAME;
}

int ShowMenu::showMenu(SDL_Renderer* des, TTF_Font* font, string path, Mix_Chunk *sound){
    Base::Free();
    bool load = Base::Load_image(path, des);
    if(load == false){
        cerr << "Could not open ShowMenu" << endl;
        return EXIT_GAME;
    }

    Text menuText[MENU+5];
    string s1 = "PLAY GAME";
    string s2 = "HOW TO PLAY";
    string s3 = "EXIT";
    menuText[0].SetColor(MAX_COLOR, MAX_COLOR, MAX_COLOR);
    menuText[0].SetText(s1);
    menuText[1].SetColor(MAX_COLOR, MAX_COLOR, MAX_COLOR);
    menuText[1].SetText(s2);
    menuText[2].SetColor(MAX_COLOR, MAX_COLOR, MAX_COLOR);
    menuText[2].SetText(s3);
    bool check[MENU] = {0, 0, 0};
    int x = 0, y = 0;

    SDL_Event event;
    while(true){
        SDL_RenderClear(des);
        Base::Render(des);
        menuText[0].RenderText(font, des, 200, 400);
        menuText[1].RenderText(font, des, 200, 460);
        menuText[2].RenderText(font, des, 200, 520);
        while(SDL_PollEvent(&event)){
            switch(event.type){
                case SDL_QUIT:
                    return EXIT_GAME;
                case SDL_MOUSEMOTION:
                    x = event.motion.x;
                    y = event.motion.y;

                    if(CheckMouse(x, y, 200, 400)){
                        check[0] = true;
                        menuText[0].SetColor(MAX_COLOR, MIN_COLOR, MIN_COLOR);
                    }
                    else{
                        check[0] = false;
                        menuText[0].SetColor(MAX_COLOR, MAX_COLOR, MAX_COLOR);
                    }

                    if(CheckMouse(x, y, 200, 460)){
                        check[1] = true;
                        menuText[1].SetColor(MAX_COLOR, MIN_COLOR, MIN_COLOR);
                    }
                    else{
                        check[1] = false;
                        menuText[1].SetColor(MAX_COLOR, MAX_COLOR, MAX_COLOR);
                    }

                    if(CheckMouse(x, y, 200, 520)){
                        check[2] = true;
                        menuText[2].SetColor(MAX_COLOR, MIN_COLOR, MIN_COLOR);
                    }
                    else{
                        check[2] = false;
                        menuText[2].SetColor(MAX_COLOR, MAX_COLOR, MAX_COLOR);
                    }
                    break;
                case SDL_MOUSEBUTTONDOWN:
                    {
                        Mix_PlayChannel( -1, sound, 0 );
                        x = event.button.x;
                        y = event.button.y;

                        if(CheckMouse(x, y, 200, 400)){
                            return START_GAME;
                        }
                        if(CheckMouse(x, y, 200, 460)){
                            int tmp = showHowToPlay(des, font, "img//backgroundhowtoplay.jpg", sound);
                            return tmp;
                        }
                        if(CheckMouse(x, y, 200, 520)){
                            return EXIT_GAME;
                        }

                    }
                    break;
                case SDL_KEYDOWN:
                    if(event.key.keysym.sym == SDLK_ESCAPE){
                        return EXIT_GAME;
                    }
                default:
                    break;
            }

        }
        SDL_RenderPresent(des);
    }
    for(int i = 0; i < MENU; i++){
        menuText[i].Free();
    }
    SDL_DestroyRenderer(des);
    return START_GAME;
}
int ShowMenu::showMenuGameOver(SDL_Renderer* des, TTF_Font* font, string path, Player p_player, Mix_Chunk* sound){
    Base::Free();
    bool load = Base::Load_image(path, des);
    if(load == false){
        cerr << "Could not open ShowMenuGameOver" << endl;
        return EXIT_GAME;
    }
    Text yourPoint;
    Text record;
    string yourpoint = "YOUR POINT: ";
    yourpoint += to_string(p_player.get_point());
    string newrecord = "RECORD: " + to_string(p_player.get_record());
    yourPoint.SetColor(MAX_COLOR, 109, 2);
    record.SetColor(MAX_COLOR, 228, 3);
    yourPoint.SetText(yourpoint);
    record.SetText(newrecord);

    Text menuText[MENU+1];
    string s1 = "PLAY AGAIN";
    string s2 = "CHOOSE CHARACTOR";
    string s3 = "EXIT";
    menuText[0].SetColor(MAX_COLOR, MAX_COLOR, MAX_COLOR);
    menuText[0].SetText(s1);
    menuText[1].SetColor(MAX_COLOR, MAX_COLOR, MAX_COLOR);
    menuText[1].SetText(s2);
    menuText[2].SetColor(MAX_COLOR, MAX_COLOR, MAX_COLOR);
    menuText[2].SetText(s3);
    bool check[MENU] = {0, 0, 0};
    int x = 0, y = 0;

    SDL_Event event;
    while(true){
        SDL_RenderClear(des);
        Base::Render(des);
        menuText[0].RenderText(font, des, 200, 400);
        menuText[1].RenderText(font, des, 200, 470);
        menuText[2].RenderText(font, des, 200, 540);

        yourPoint.RenderText(font, des, 680, 310);
        record.RenderText(font, des, 680, 380);

        while(SDL_PollEvent(&event)){
            switch(event.type){
                case SDL_QUIT:
                    return EXIT_GAME;
                case SDL_MOUSEMOTION:
                    x = event.motion.x;
                    y = event.motion.y;

                    if(CheckMouse(x, y, 200, 400)){
                        check[0] = true;
                        menuText[0].SetColor(MAX_COLOR, MIN_COLOR, MIN_COLOR);
                    }
                    else{
                        check[0] = false;
                        menuText[0].SetColor(MAX_COLOR, MAX_COLOR, MAX_COLOR);
                    }

                    if(CheckMouse(x, y, 200, 470)){
                        check[1] = true;
                        menuText[1].SetColor(MAX_COLOR, MIN_COLOR, MIN_COLOR);
                    }
                    else{
                        check[1] = false;
                        menuText[1].SetColor(MAX_COLOR, MAX_COLOR, MAX_COLOR);
                    }

                    if(CheckMouse(x, y, 200, 540)){
                        check[2] = true;
                        menuText[2].SetColor(MAX_COLOR, MIN_COLOR, MIN_COLOR);
                    }
                    else{
                        check[2] = false;
                        menuText[2].SetColor(MAX_COLOR, MAX_COLOR, MAX_COLOR);
                    }
                    break;
                case SDL_MOUSEBUTTONDOWN:
                    {
                        Mix_PlayChannel( -1, sound, 0 );
                        x = event.button.x;
                        y = event.button.y;

                        if(CheckMouse(x, y, 200, 400)){
                            return START_GAME;
                        }
                        if(CheckMouse(x, y, 200, 470)){
                            return CHOOSE_CHAR;
                        }
                        if(CheckMouse(x, y, 200, 540)){
                            return EXIT_GAME;
                        }

                    }
                    break;
                case SDL_KEYDOWN:
                    if(event.key.keysym.sym == SDLK_ESCAPE){
                        return EXIT_GAME;
                    }
                default:
                    break;
            }

        }
        SDL_RenderPresent(des);
    }
    for(int i = 0; i < MENU; i++){
        menuText[i].Free();
    }
    SDL_DestroyRenderer(des);
    return START_GAME;
}
int ShowMenu::chooseChar(SDL_Renderer* des, TTF_Font* font, string path, Mix_Chunk* sound){
    Base::Free();
    bool load = Base::Load_image(path, des);
    if(load == false){
        cerr << "Could not open ChooseChar" << endl;
        return EXIT_GAME;
    }
    
    Text menuChar[MENU_CHAR+5];
    string s1 = "CHARACTOR 1";
    string s2 = "CHARACTOR 2";
    string s3 = "CHARACTOR 3";
    string s4 = "CHARACTOR 4";
    string s5 = "EXIT";

    menuChar[0].SetColor(MAX_COLOR, MAX_COLOR, MAX_COLOR);
    menuChar[0].SetText(s1);
    menuChar[1].SetColor(MAX_COLOR, MAX_COLOR, MAX_COLOR);
    menuChar[1].SetText(s2);
    menuChar[2].SetColor(MAX_COLOR, MAX_COLOR, MAX_COLOR);
    menuChar[2].SetText(s3);
    menuChar[3].SetColor(MAX_COLOR, MAX_COLOR, MAX_COLOR);
    menuChar[3].SetText(s4);
    menuChar[4].SetColor(MAX_COLOR, MAX_COLOR, MAX_COLOR);
    menuChar[4].SetText(s5);
    bool check[MENU_CHAR] = {0, 0, 0, 0};
    int x = 0, y = 0;

    SDL_Event event;
    while(true){
        SDL_RenderClear(des);
        Base::Render(des);
        menuChar[0].RenderText(font, des, 300, 100);
        menuChar[1].RenderText(font, des, 300, 200);
        menuChar[2].RenderText(font, des, 300, 300);
        menuChar[3].RenderText(font, des, 300, 400);
        menuChar[4].RenderText(font, des, 300, 500);

        while(SDL_PollEvent(&event)){
            switch(event.type){
                case SDL_QUIT:
                    return EXIT_GAME;
                case SDL_MOUSEMOTION:
                    x = event.motion.x;
                    y = event.motion.y;

                    if(CheckMouse(x, y, 300, 100)){
                        check[0] = true;
                        menuChar[0].SetColor(MAX_COLOR, MIN_COLOR, MIN_COLOR);
                    }
                    else{
                        check[0] = false;
                        menuChar[0].SetColor(MAX_COLOR, MAX_COLOR, MAX_COLOR);
                    }

                    if(CheckMouse(x, y, 300, 200)){
                        check[1] = true;
                        menuChar[1].SetColor(MAX_COLOR, MIN_COLOR, MIN_COLOR);
                    }
                    else{
                        check[1] = false;
                        menuChar[1].SetColor(MAX_COLOR, MAX_COLOR, MAX_COLOR);
                    }

                    if(CheckMouse(x, y, 300, 300)){
                        check[2] = true;
                        menuChar[2].SetColor(MAX_COLOR, MIN_COLOR, MIN_COLOR);
                    }
                    else{
                        check[2] = false;
                        menuChar[2].SetColor(MAX_COLOR, MAX_COLOR, MAX_COLOR);
                    }

                    if(CheckMouse(x, y, 300, 400)){
                        check[3] = true;
                        menuChar[3].SetColor(MAX_COLOR, MIN_COLOR, MIN_COLOR);
                    }
                    else{
                        check[3] = false;
                        menuChar[3].SetColor(MAX_COLOR, MAX_COLOR, MAX_COLOR);
                    }

                    if(CheckMouse(x, y, 300, 500)){
                        check[4] = true;
                        menuChar[4].SetColor(MAX_COLOR, MIN_COLOR, MIN_COLOR);
                    }
                    else{
                        check[4] = false;
                        menuChar[4].SetColor(MAX_COLOR, MAX_COLOR, MAX_COLOR);
                    }
                    break;
                case SDL_MOUSEBUTTONDOWN:
                    {
                        Mix_PlayChannel( -1, sound, 0 );
                        x = event.button.x;
                        y = event.button.y;

                        if(CheckMouse(x, y, 300, 100)){
                            return CHAR_1;
                        }
                        if(CheckMouse(x, y, 300, 200)){
                            return CHAR_2;
                        }
                        if(CheckMouse(x, y, 300, 300)){
                            return CHAR_3;
                        }
                        if(CheckMouse(x, y, 300, 400)){
                            return CHAR_4;
                        }
                        if(CheckMouse(x, y, 300, 500)){
                            return EXIT_GAME;
                        }

                    }
                    break;
                case SDL_KEYDOWN:
                    if(event.key.keysym.sym == SDLK_ESCAPE){
                        return EXIT_GAME;
                    }
                default:
                    break;
            }

        }
        SDL_RenderPresent(des);
    }
    for(int i = 0; i < MENU_CHAR; i++){
        menuChar[i].Free();
    }
    SDL_DestroyRenderer(des);
    return CHAR_1;
}
int ShowMenu::menuPaused(SDL_Renderer* des, TTF_Font* font, string path, Mix_Chunk* sound, bool &pause){
    Base::Free();
    bool load = Base::Load_image(path, des);
    if(load == false){
        cerr << "Could not open ShowMenuPaused" << endl;
        return EXIT_GAME;
    }

    Text menuText[MENU];
    string s1 = "CONTINUE";
    string s2 = "EXIT";
    menuText[0].SetColor(MAX_COLOR, MAX_COLOR, MAX_COLOR);
    menuText[0].SetText(s1);
    menuText[1].SetColor(MAX_COLOR, MAX_COLOR, MAX_COLOR);
    menuText[1].SetText(s2);
    bool check[MENU] = {0, 0};
    int x = 0, y = 0;

    SDL_Event event;
    while(true){
        SDL_RenderClear(des);
        Base::Render(des);
        menuText[0].RenderText(font, des, 400, 220);
        menuText[1].RenderText(font, des, 450, 440);

        while(SDL_PollEvent(&event)){
            switch(event.type){
                case SDL_QUIT:
                    return EXIT_GAME;
                case SDL_MOUSEMOTION:
                    x = event.motion.x;
                    y = event.motion.y;

                    if(CheckMouse(x, y, 400, 220)){
                        check[0] = true;
                        menuText[0].SetColor(MAX_COLOR, MIN_COLOR, MIN_COLOR);
                    }
                    else{
                        check[0] = false;
                        menuText[0].SetColor(MAX_COLOR, MAX_COLOR, MAX_COLOR);
                    }

                    if(CheckMouse(x, y, 450, 440)){
                        check[1] = true;
                        menuText[1].SetColor(MAX_COLOR, MIN_COLOR, MIN_COLOR);
                    }
                    else{
                        check[1] = false;
                        menuText[1].SetColor(MAX_COLOR, MAX_COLOR, MAX_COLOR);
                    }
                    break;
                case SDL_MOUSEBUTTONDOWN:
                    {
                        Mix_PlayChannel( -1, sound, 0 );
                        x = event.button.x;
                        y = event.button.y;

                        if(CheckMouse(x, y, 400, 220)){
                            pause = false;
                            return CONTINUE;
                        }
                        if(CheckMouse(x, y, 450, 440)){
                            return EXIT_GAME;
                        }
                    }
                    break;
                case SDL_KEYDOWN:
                    if(event.key.keysym.sym == SDLK_ESCAPE){
                        return EXIT_GAME;
                    }
                    else if(event.key.keysym.sym == SDLK_SPACE){
                        return PLAY_AGAIN;
                    }
                default:
                    break;
            }

        }
        SDL_RenderPresent(des);
    }
    for(int i = 0; i < MENU-1; i++){
        menuText[i].Free();
    }
    SDL_DestroyRenderer(des);
    return START_GAME;
}

int ShowMenu::menuWinGame(SDL_Renderer* des, TTF_Font* font, string path, Mix_Chunk* sound, bool& win){
    Base::Free();
    bool load = Base::Load_image(path, des);
    if(load == false){
        cerr << "Could not open ShowMenuGameOver" << endl;
        return EXIT_GAME;
    }

    Text menuText[MENU+1];
    string s1 = "PLAY AGAIN";
    string s2 = "CHOOSE CHARACTOR";
    string s3 = "EXIT";
    menuText[0].SetColor(MAX_COLOR, MAX_COLOR, MAX_COLOR);
    menuText[0].SetText(s1);
    menuText[1].SetColor(MAX_COLOR, MAX_COLOR, MAX_COLOR);
    menuText[1].SetText(s2);
    menuText[2].SetColor(MAX_COLOR, MAX_COLOR, MAX_COLOR);
    menuText[2].SetText(s3);
    bool check[MENU] = {0, 0, 0};
    int x = 0, y = 0;

    SDL_Event event;
    while(true){
        SDL_RenderClear(des);
        Base::Render(des);
        menuText[0].RenderText(font, des, 200, 400);
        menuText[1].RenderText(font, des, 200, 470);
        menuText[2].RenderText(font, des, 200, 540);

        while(SDL_PollEvent(&event)){
            switch(event.type){
                case SDL_QUIT:
                    return EXIT_GAME;
                case SDL_MOUSEMOTION:
                    x = event.motion.x;
                    y = event.motion.y;

                    if(CheckMouse(x, y, 200, 400)){
                        check[0] = true;
                        menuText[0].SetColor(MAX_COLOR, MIN_COLOR, MIN_COLOR);
                    }
                    else{
                        check[0] = false;
                        menuText[0].SetColor(MAX_COLOR, MAX_COLOR, MAX_COLOR);
                    }

                    if(CheckMouse(x, y, 200, 470)){
                        check[1] = true;
                        menuText[1].SetColor(MAX_COLOR, MIN_COLOR, MIN_COLOR);
                    }
                    else{
                        check[1] = false;
                        menuText[1].SetColor(MAX_COLOR, MAX_COLOR, MAX_COLOR);
                    }

                    if(CheckMouse(x, y, 200, 540)){
                        check[2] = true;
                        menuText[2].SetColor(MAX_COLOR, MIN_COLOR, MIN_COLOR);
                    }
                    else{
                        check[2] = false;
                        menuText[2].SetColor(MAX_COLOR, MAX_COLOR, MAX_COLOR);
                    }
                    break;
                case SDL_MOUSEBUTTONDOWN:
                    {
                        Mix_PlayChannel( -1, sound, 0 );
                        x = event.button.x;
                        y = event.button.y;

                        if(CheckMouse(x, y, 200, 400)){
                            win = false;
                            return PLAY_AGAIN;
                        }
                        if(CheckMouse(x, y, 200, 470)){
                            return CHOOSE_CHAR;
                        }
                        if(CheckMouse(x, y, 200, 540)){
                            return EXIT_GAME;
                        }

                    }
                    break;
                case SDL_KEYDOWN:
                    if(event.key.keysym.sym == SDLK_ESCAPE){
                        return EXIT_GAME;
                    }
                default:
                    break;
            }

        }
        SDL_RenderPresent(des);
    }
    for(int i = 0; i < MENU; i++){
        menuText[i].Free();
    }
    SDL_DestroyRenderer(des);
    return START_GAME;
}