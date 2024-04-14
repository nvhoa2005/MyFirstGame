#include "Menu.h"
ShowMenu::ShowMenu(){

}

ShowMenu::~ShowMenu(){

}

bool ShowMenu::CheckMouseInOut(const int &x, const int &y, const int& a, const int&b)
{
    if(x >= a && x <= a + WIDTH_TEXT && y >= b && y <= b + HEIGHT_TEXT){
        return true;
    }
    return false;
}

int ShowMenu::showHowToPlay(SDL_Renderer* des, TTF_Font* font, string path, Mix_Chunk* sound){
    bool ret = Base::Load_image(path, des);
    if(ret == false){
        cerr << "Could not open ShowHowToPlay" << endl;
        return EXIT_GAME;
    }

    Text menuText[MENU];
    string s1 = "PLAY GAME";
    string s2 = "HOW TO PLAY:";
    string s3 = "EXIT";
    menuText[0].SetColor(MAX_COLOR, MAX_COLOR, MAX_COLOR);
    menuText[0].SetText(s1);
    menuText[1].SetColor(MAX_COLOR, 82, 6);
    menuText[1].SetText(s2);
    menuText[2].SetColor(MAX_COLOR, MAX_COLOR, MAX_COLOR);
    menuText[2].SetText(s3);
    bool selected[3] = {0, 0, 0};
    int x = 0, y = 0;

    SDL_Event event;
    while(true){
        Base::Render(des, NULL);
        menuText[0].LoadText(font, des);
        menuText[0].RenderText(des, 200, 390);
        menuText[1].LoadText(font, des);
        menuText[1].RenderText(des, 50, 150);
        menuText[2].LoadText(font, des);
        menuText[2].RenderText(des, 200, 450);

        while(SDL_PollEvent(&event)){
            switch(event.type){
                case SDL_QUIT:
                    return EXIT_GAME;
                case SDL_MOUSEMOTION:
                    x = event.motion.x;
                    y = event.motion.y;

                    if(CheckMouseInOut(x, y, 200, 390)){
                        if(selected[0] == false){
                            selected[0] == true;
                            menuText[0].SetColor(MAX_COLOR, MIN_COLOR, MIN_COLOR);
                        }
                    }
                    else{
                        selected[0] == false;
                        menuText[0].SetColor(MAX_COLOR, MAX_COLOR, MAX_COLOR);
                    }

                    if(CheckMouseInOut(x, y, 200, 450)){
                        if(selected[2] == false){
                            selected[2] == true;
                            menuText[2].SetColor(MAX_COLOR, MIN_COLOR, MIN_COLOR);
                        }
                    }
                    else{
                        selected[2] == false;
                        menuText[2].SetColor(MAX_COLOR, MAX_COLOR, MAX_COLOR);
                    }
                    break;
                case SDL_MOUSEBUTTONDOWN:
                    {
                        Mix_PlayChannel( -1, sound, 0 );
                        x = event.button.x;
                        y = event.button.y;

                        if(CheckMouseInOut(x, y, 200, 390)){
                            return START_GAME;
                        }
                        if(CheckMouseInOut(x, y, 200, 450)){
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
    return 1;
}

int ShowMenu::showMenu(SDL_Renderer* des, TTF_Font* font, string path, Mix_Chunk *sound){
    bool ret = Base::Load_image(path, des);
    if(ret == false){
        cerr << "Could not open ShowMenu" << endl;
        return EXIT_GAME;
    }

    Text menuText[3];
    string s1 = "PLAY GAME";
    string s2 = "HOW TO PLAY";
    string s3 = "EXIT";
    menuText[0].SetColor(MAX_COLOR, MAX_COLOR, MAX_COLOR);
    menuText[0].SetText(s1);
    menuText[1].SetColor(MAX_COLOR, MAX_COLOR, MAX_COLOR);
    menuText[1].SetText(s2);
    menuText[2].SetColor(MAX_COLOR, MAX_COLOR, MAX_COLOR);
    menuText[2].SetText(s3);
    bool selected[3] = {0, 0, 0};
    int x = 0, y = 0;

    SDL_Event event;
    while(true){
        Base::Render(des, NULL);
        menuText[0].LoadText(font, des);
        menuText[0].RenderText(des, 200, 400);
        menuText[1].LoadText(font, des);
        menuText[1].RenderText(des, 200, 460);
        menuText[2].LoadText(font, des);
        menuText[2].RenderText(des, 200, 520);
        while(SDL_PollEvent(&event)){
            switch(event.type){
                case SDL_QUIT:
                    return EXIT_GAME;
                case SDL_MOUSEMOTION:
                    x = event.motion.x;
                    y = event.motion.y;

                    if(CheckMouseInOut(x, y, 200, 400)){
                        if(selected[0] == false){
                            selected[0] == true;
                            menuText[0].SetColor(MAX_COLOR, MIN_COLOR, MIN_COLOR);
                        }
                    }
                    else{
                        selected[0] == false;
                        menuText[0].SetColor(MAX_COLOR, MAX_COLOR, MAX_COLOR);
                    }

                    if(CheckMouseInOut(x, y, 200, 460)){
                        if(selected[1] == false){
                            selected[1] == true;
                            menuText[1].SetColor(MAX_COLOR, MIN_COLOR, MIN_COLOR);
                        }
                    }
                    else{
                        selected[1] == false;
                        menuText[1].SetColor(MAX_COLOR, MAX_COLOR, MAX_COLOR);
                    }

                    if(CheckMouseInOut(x, y, 200, 520)){
                        if(selected[2] == false){
                            selected[2] == true;
                            menuText[2].SetColor(MAX_COLOR, MIN_COLOR, MIN_COLOR);
                        }
                    }
                    else{
                        selected[2] == false;
                        menuText[2].SetColor(MAX_COLOR, MAX_COLOR, MAX_COLOR);
                    }
                    break;
                case SDL_MOUSEBUTTONDOWN:
                    {
                        Mix_PlayChannel( -1, sound, 0 );
                        x = event.button.x;
                        y = event.button.y;

                        if(CheckMouseInOut(x, y, 200, 400)){
                            return START_GAME;
                        }
                        if(CheckMouseInOut(x, y, 200, 460)){
                            int tmp = showHowToPlay(des, font, "img//backgroundhowtoplay.jpg", sound);
                            return tmp;
                        }
                        if(CheckMouseInOut(x, y, 200, 520)){
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
    return 1;
}
int ShowMenu::showMenuGameOver(SDL_Renderer* des, TTF_Font* font, string path, Player p_player, Mix_Chunk* sound){
    bool ret = Base::Load_image(path, des);
    if(ret == false){
        cerr << "Could not open ShowMenuGameOver" << endl;
        return EXIT_GAME;
    }
    Text yourPoint;
    Text record;
    string yourpoint = "YOUR POINT: ";
    yourpoint += to_string(p_player.get_point());
    string newrecord = "RECORD: ";
    newrecord += to_string(p_player.get_record());
    yourPoint.SetColor(MAX_COLOR, 109, 2);
    record.SetColor(MAX_COLOR, 228, 3);
    yourPoint.SetText(yourpoint);
    record.SetText(newrecord);

    Text menuText[3];
    string s1 = "PLAY AGAIN";
    string s3 = "EXIT";
    menuText[0].SetColor(MAX_COLOR, MAX_COLOR, MAX_COLOR);
    menuText[0].SetText(s1);
    menuText[2].SetColor(MAX_COLOR, MAX_COLOR, MAX_COLOR);
    menuText[2].SetText(s3);
    bool selected[3] = {0, 0, 0};
    int x = 0, y = 0;

    SDL_Event event;
    while(true){
        Base::Render(des, NULL);
        menuText[0].LoadText(font, des);
        menuText[0].RenderText(des, 200, 400);
        menuText[2].LoadText(font, des);
        menuText[2].RenderText(des, 200, 460);

        yourPoint.LoadText(font, des);
        yourPoint.RenderText(des, 680, 310);
        record.LoadText(font, des);
        record.RenderText(des, 680, 380);

        while(SDL_PollEvent(&event)){
            switch(event.type){
                case SDL_QUIT:
                    return EXIT_GAME;
                case SDL_MOUSEMOTION:
                    x = event.motion.x;
                    y = event.motion.y;

                    if(CheckMouseInOut(x, y, 200, 400)){
                        if(selected[0] == false){
                            selected[0] == true;
                            menuText[0].SetColor(MAX_COLOR, MIN_COLOR, MIN_COLOR);
                        }
                    }
                    else{
                        selected[0] == false;
                        menuText[0].SetColor(MAX_COLOR, MAX_COLOR, MAX_COLOR);
                    }

                    if(CheckMouseInOut(x, y, 200, 460)){
                        if(selected[2] == false){
                            selected[2] == true;
                            menuText[2].SetColor(MAX_COLOR, MIN_COLOR, MIN_COLOR);
                        }
                    }
                    else{
                        selected[2] == false;
                        menuText[2].SetColor(MAX_COLOR, MAX_COLOR, MAX_COLOR);
                    }
                    break;
                case SDL_MOUSEBUTTONDOWN:
                    {
                        Mix_PlayChannel( -1, sound, 0 );
                        x = event.button.x;
                        y = event.button.y;

                        if(CheckMouseInOut(x, y, 200, 400)){
                            return START_GAME;
                        }
                        if(CheckMouseInOut(x, y, 200, 460)){
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
    return 1;
}
