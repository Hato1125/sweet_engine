#ifndef ENGINE_CORE_GAME_LOOP_H_
#define ENGINE_CORE_GAME_LOOP_H_

#include <cmath>
#include <cstdint>
#include <chrono>
#include <thread>

#include <SDL.h>

namespace sweet{
    class GameLoop {
    private:
        std::chrono::high_resolution_clock::time_point _start_clock;

        double _frame_sec;
        double _delta_sec;
        double _max_frame_sec;
        double _second_counter;

        uint32_t _framerate;
        uint32_t _frame_count;

        void begin_calc_frame_sec();
        void end_limmit_framerate();
        void end_calc_frame_sec();
        void end_calc_framerate();
        double get_now_frame_sec() const;

    public:
        GameLoop();

        void begin_update();
        void end_update();

        void set_max_framerate(double framerate);

        double get_frame_sec() const;
        double get_delta_sec() const;
        uint32_t get_framerate() const;
    };
}

#endif // ENGINE_CORE_GAME_LOOP_H_