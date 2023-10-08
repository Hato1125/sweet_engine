#ifndef ENGINE_CORE_GAME_LOOP_H_
#define ENGINE_CORE_GAME_LOOP_H_

#include <cstdint>

#include <SDL.h>

namespace sweet{
    class GameLoop {
    private:
        float _last_time;
        float _delta_time;
        float _max_framerate_ms;
        float _ms_counter;
        float _framerate;
        float _framerate_counter;

        void calc_delta_time();
        void calc_framerate();
        void limmit_framerate();

    public:
        void update();

        void set_max_framerate(float fps);

        float get_delta_time() const;
        uint32_t get_framerate() const;
    };
}

#endif // ENGINE_CORE_GAME_LOOP_H_