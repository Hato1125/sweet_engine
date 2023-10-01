#ifndef ENGINE_CORE_APPLICATION_H_
#define ENGINE_CORE_APPLICATION_H_

#include <memory>
#include <string>
#include <cstdint>
#include <utility>

#include <SDL.h>

#include "application_loop_info.h"

namespace sweet {
    class Application {
    private:
        std::unique_ptr<SDL_Window, decltype(&SDL_DestroyWindow)> _window;
        std::unique_ptr<SDL_Renderer, decltype(&SDL_DestroyRenderer)> _renderer;

    public:
        bool is_running;
        bool is_auto_finish;

        Application(
            std::string title,
            std::pair<uint32_t, uint32_t> pos,
            std::pair<uint32_t, uint32_t> size,
            uint32_t window_flags = SDL_WINDOW_SHOWN,
            uint32_t renderer_falgs = SDL_RENDERER_PRESENTVSYNC
                | SDL_RENDERER_TARGETTEXTURE
                | SDL_RENDERER_ACCELERATED,
            int32_t graphics_diriver_index = -1
        );

        void running(const ApplicationLoopInfo& info);

        [[nodiscard]] SDL_Window* get_window() const;
        [[nodiscard]] SDL_Renderer* get_renderer() const;
    };
}

#endif // ENGINE_CORE_APPLICATION_H_