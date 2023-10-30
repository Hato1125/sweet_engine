#include "game_loop.h"

#include <iostream>

namespace sweet {
    GameLoop::GameLoop() {
        _frame_sec = 0.0;
        _delta_sec = 0.0;
        _max_frame_sec = -1.0;
        _second_counter = 0.0;
    }

    void GameLoop::begin_calc_frame_sec() {
        _start_clock = std::chrono::steady_clock::now();
    }

    void GameLoop::end_limmit_framerate() {
        if(_max_frame_sec <= -1.0)
            return;

        double frame_sec = get_now_frame_sec();

        if (frame_sec < _max_frame_sec) {
            double sleep_s = (_max_frame_sec - frame_sec) * 1000000.0;
            std::this_thread::sleep_for(
                std::chrono::microseconds(static_cast<long>(sleep_s))
            );
        }
    }

    void GameLoop::end_calc_frame_sec() {
        _frame_sec = get_now_frame_sec();
        _delta_sec = _max_frame_sec > -1.0 && _frame_sec > _max_frame_sec
            ? _max_frame_sec
            : _frame_sec;
    }

    void GameLoop::end_calc_framerate() {
        _second_counter += _frame_sec;
        ++_frame_count;

        if(_second_counter >= 1.0) {
            _framerate = _frame_count;
            _frame_count = 0;
            _second_counter = 0.0;
        }
    }

    double GameLoop::get_now_frame_sec() const {
        const auto now_clock = std::chrono::high_resolution_clock::now();
        const auto frame_us = std::chrono::duration<double, std::micro>(
            now_clock - _start_clock
        ).count();

        return frame_us / 1000000.0;
    }

    void GameLoop::begin_update() {
        begin_calc_frame_sec();
    }

    void GameLoop::end_update() {
        end_limmit_framerate();
        end_calc_frame_sec();
        end_calc_framerate();
    }

    void GameLoop::set_max_framerate(double framerate) {
        _max_frame_sec = framerate <= -1.0 ? -1.0 : 1.0 / framerate;
    }

    double GameLoop::get_frame_sec() const {
        return _frame_sec;
    }

    double GameLoop::get_delta_sec() const {
        return _delta_sec;
    }

    uint32_t GameLoop::get_framerate() const {
        return _framerate;
    }
}