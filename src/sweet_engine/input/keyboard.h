#ifndef ENGINE_INPUT_KEYBOARD_H_
#define ENGINE_INPUT_KEYBOARD_H_

#include <array>
#include <cstdint>

#include <SDL.h>

namespace sweet {
    class Keyboard final {
    private:
        Keyboard() = delete;
        Keyboard(const Keyboard&) = delete;
        Keyboard(Keyboard&&) = delete;
        ~Keyboard() = delete;

        static std::array<int8_t, 256> _key_value;

        static bool _is_update;
        static bool _is_counting_frame;
        static bool _is_called_update;
        static int8_t _update_counter;
        static int8_t _frame_counter;

        static void update_key_value();

    public:
        static void update();
        static void update_event(const SDL_Event &event);

        static bool is_pushing(SDL_Scancode key);
        static bool is_pushed(SDL_Scancode key);
        static bool is_separate(SDL_Scancode key);
    };
}
#endif // ENGINE_INPUT_KEYBOARD_H_