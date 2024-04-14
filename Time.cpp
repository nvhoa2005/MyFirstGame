#include "Time.h"
#include "Function.h"

Time::Time()
{
    start_tick = 0;
    pause_tick = 0;
    is_pause = false;
    is_start = false;
}

Time::~Time()
{

}

void Time::start()
{
    is_start = true;
    is_pause = false;
    start_tick = SDL_GetTicks();
}

void Time::stop()
{
    is_pause = false;
    is_start = false;
}

void Time::pause()
{
    if(is_start == true && is_pause == false){
        is_pause = true;
        pause_tick = SDL_GetTicks() - start_tick;
    }
}

void Time::unpause()
{
    if(is_pause == true)
    {
        is_pause = false;
        start_tick = SDL_GetTicks() - pause_tick;
        pause_tick = 0;
    }
}

int Time::get_ticks()
{
    if(is_start == true){
        if(is_pause == true){
            return pause_tick;
        }
        else{
            return SDL_GetTicks() - start_tick;
        }
    }
    return 0;
}

bool Time::started(){
    return is_start;
}

bool Time::paused(){
    return is_pause;
}
