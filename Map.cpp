#include "Map.h"
void GameMap::LoadMap(string &name){
    ifstream file(name);
    if(!file.is_open()){
        cerr << "Cannot open file: " << name << endl;
        return;
    }

    gameMap.max_x = 0;
    gameMap.max_y = 0;

    for(int i = 0; i < MAXMAPY; i++){
        for(int j = 0; j < MAXMAPX; j++){
            int val;
            file >> val;
            gameMap.square[i][j] = val;
            if(val > 0){
                if(j > gameMap.max_x){
                    gameMap.max_x = j;
                }
                if(i > gameMap.max_y){
                    gameMap.max_y = i;
                }
            }
        }
    }

    gameMap.max_x = (gameMap.max_x + 1)*SQUARE_SIZE;
    gameMap.max_y = (gameMap.max_y + 1)*SQUARE_SIZE;

    gameMap.start_x = 0;
    gameMap.start_y = 0;

    gameMap.file_name = name;
    file.close();
}

void GameMap::LoadSquare(SDL_Renderer *screen){
    string file_img;
    ifstream file;

    for(int i = 0; i < MAX_SQUARE; i++){
        file_img = "img//" + to_string(i) + ".png";
        file.open(file_img);
        if(!file.is_open()) continue;

        file.close();

        square[i].Load_image(file_img, screen);
    }
}

void GameMap::DrawMap(SDL_Renderer* screen){
    int x1 = 0;
    int x2 = 0;

    int y1 = 0;
    int y2 = 0;

    int map_x = 0;
    int map_y = 0;

    map_x = gameMap.start_x/SQUARE_SIZE;
    x1 = (gameMap.start_x %SQUARE_SIZE)*-1;
    x2 = x1 + SCREEN_WIDTH + (x1 == 0 ? 0 : SQUARE_SIZE);

    map_y = gameMap.start_y/SQUARE_SIZE;
    y1 = (gameMap.start_y%SQUARE_SIZE)*-1;
    y2 = y1 + SCREEN_HEIGHT + (y1 == 0 ? 0 : SQUARE_SIZE);

    for(int i = y1; i < y2; i+= SQUARE_SIZE){
        map_x = gameMap.start_x/SQUARE_SIZE;
        for(int j = x1; j < x2; j+= SQUARE_SIZE){
            int val = gameMap.square[map_y][map_x];
            if(val > 0){
                square[val].SetRect(j, i);
                square[val].Render(screen);
            }
            map_x++;
        }
        map_y++;
    }
}
