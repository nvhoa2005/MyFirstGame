#ifndef _DEFS__H
#define _DEFS__H

#include <bits/stdc++.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>

#define MAX_SOUND 5
#define MAX_SQUARE 10

using namespace std;

static SDL_Window* g_window = NULL;
static SDL_Renderer* g_screen = NULL;
static SDL_Event g_event;
static Mix_Chunk* g_sound[MAX_SOUND];
static Mix_Music* g_music;
static TTF_Font* font = NULL;
static TTF_Font* menu = NULL;

const int FRAME_PER_SECOND = 35; //fps
const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 640;
const int SCREEN_BPP = 32;

const int MAX_COLOR = 255;
const int MIN_COLOR = 0;

const int WIDTH_TEXT = 360;
const int HEIGHT_TEXT = 40;

#define BLANK_SQUARE 0

#define SQUARE_SIZE 64

#define MAX_MAP_X 400
#define MAX_MAP_Y 10

#define CHAR_1 1
#define CHAR_2 2
#define CHAR_3 3
#define CHAR_4 4

#define PLAY_AGAIN 0
#define START_GAME 0
#define CHOOSE_CHAR 1
#define EXIT_GAME 5

#define MENU 3
#define MENU_CHAR 5


#endif // _DEFS__H
