#include "game_loop.h"

namespace sweet {
    void GameLoop::calc_delta_time() {
        double now_tick = static_cast<double>(SDL_GetTicks());

        _frame_ms = (now_tick - _last_time) / 1000.0f;
        _last_time = now_tick;

        _delta_time = _max_framerate_ms >= 0 && _frame_ms > _max_framerate_ms
            ? _max_framerate_ms
            : _frame_ms;
    }

    void GameLoop::calc_framerate() {
        _ms_counter += _delta_time;
        ++_framerate_counter;

        if(_ms_counter >= 1.0f) {
            _framerate = _framerate_counter;
            _framerate_counter = 0;
            _ms_counter = 0;
        }
    }

    void GameLoop::limmit_framerate() {
        while(_max_framerate_ms >= 0
            && SDL_GetTicks() < _last_time + _max_framerate_ms * 1000.0);
    }

    void GameLoop::update() {
        limmit_framerate();
        calc_delta_time();
        calc_framerate();
    }

    void GameLoop::set_max_framerate(float fps) {
        _max_framerate_ms = fps <= 0 ? -1 : 1.0f / fps;
    }

    float GameLoop::get_frame_ms() const {
        return _frame_ms;
    }

    float GameLoop::get_delta_time() const {
        return _delta_time;
    }

    uint32_t GameLoop::get_framerate() const {
        return _framerate;
    }
}