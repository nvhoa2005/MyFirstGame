#ifndef _FUNCTION__H
#define _FUNCTION__H

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

const int COLOR_KEY_R = 167;
const int COLOR_KEY_G = 175;
const int COLOR_KEY_B = 180;

#define BLANK_SQUARE 0

#define SQUARE_SIZE 64

#define MAXMAPX 400
#define MAXMAPY 10

#define START_GAME 0
#define EXIT_GAME 2

#define MENU 3


#endif // _FUNCTION__H
