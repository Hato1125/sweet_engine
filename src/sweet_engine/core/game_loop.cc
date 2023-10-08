#include "game_loop.h"

namespace sweet {
    void GameLoop::calc_delta_time() {
        _delta_time = (SDL_GetTicks() - _last_time) / 1000.0f;
        _last_time = SDL_GetTicks();

        if(_max_framerate_ms >= 0 && _delta_time > _max_framerate_ms)
            _delta_time = _max_framerate_ms;
    }

    void GameLoop::calc_framerate() {
        _ms_counter += _delta_time;
        _framerate_counter++;

        if(_ms_counter >= 1.0f) {
            _framerate = _framerate_counter;
            _framerate_counter = 0;
            _ms_counter = 0;
        }
    }

    void GameLoop::limmit_framerate() {
        while(_max_framerate_ms >= 0
            && SDL_GetTicks() <= _last_time + _max_framerate_ms * 1000.0f);
    }

    void GameLoop::update() {
        calc_delta_time();
        limmit_framerate();
        calc_framerate();
    }

    void GameLoop::set_max_framerate(float fps) {
        _max_framerate_ms = fps <= 0 ? -1 : 1.0f / fps;
    }

    float GameLoop::get_delta_time() const {
        return _delta_time;
    }

    uint32_t GameLoop::get_framerate() const {
        return _framerate;
    }
}