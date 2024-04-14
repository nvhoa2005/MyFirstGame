#ifndef _TIME__
#define _TIME__

class Time
{
public:
    Time();
    ~Time();

    void start();
    void stop();
    void pause();
    void unpause();

    int get_ticks();

    bool started();
    bool paused();
private:
    int start_tick;
    int pause_tick;

    bool is_pause;
    bool is_start;

};


#endif // _TIME__
