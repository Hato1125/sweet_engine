#include "keyboard.h"

#include <iostream>

namespace sweet {
    std::array<int8_t, 256> Keyboard::_key_value = {};

    bool Keyboard::_is_update = false;
    bool Keyboard::_is_counting_frame = false;
    bool Keyboard::_is_called_update = false;
    int8_t Keyboard::_frame_counter = 0;
    int8_t Keyboard::_update_counter = 0;

    void Keyboard::update_key_value() {
        auto state = SDL_GetKeyboardState(nullptr);

        for(int i = 0; i < _key_value.size(); i++) {
            if(state[i] == 1)
                _key_value[i] = is_pushing(static_cast<SDL_Scancode>(i)) ? 1 : 2;
            else
                _key_value[i] = is_pushing(static_cast<SDL_Scancode>(i)) ? -1 : 0;
        }
    }

    void Keyboard::update() {
        if(_is_update && !_is_counting_frame && _update_counter < 2) {
            update_key_value();
            _update_counter++;
        }

        if(_is_counting_frame) {
            update_key_value();

            if(_frame_counter > 1)
                _is_counting_frame = false;

            _frame_counter++;
        }
    }

    void Keyboard::update_event(const SDL_Event &event) {
        switch(event.type) {
            case SDL_KEYDOWN: {
                _is_update = true;
                _is_counting_frame = false;
                break;
            }

            case SDL_KEYUP: {
                _is_update = false;
                _is_counting_frame = true;
                _is_called_update = false;
                _frame_counter = 0;
                _update_counter = 0;
                break;
            }
        }
    }

    bool Keyboard::is_pushing(SDL_Scancode key) {
        return _key_value[static_cast<int>(key)] > 0;
    }

    bool Keyboard::is_pushed(SDL_Scancode key) {
        return _key_value[static_cast<int>(key)] == 2;
    }

    bool Keyboard::is_separate(SDL_Scancode key) {
        return _key_value[static_cast<int>(key)] == -1;
    }
}