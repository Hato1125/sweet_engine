#ifndef ENGINE_CORE_APPLICATION_H_
#define ENGINE_CORE_APPLICATION_H_

#include <memory>
#include <string>
#include <cstdint>

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

#include <size.h>
#include <point.h>

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
            const std::string &title,
            const Point<uint32_t> &point,
            const Size<uint32_t> &size,
            uint32_t window_flags = SDL_WINDOW_SHOWN,
            uint32_t renderer_falgs = SDL_RENDERER_PRESENTVSYNC
                | SDL_RENDERER_TARGETTEXTURE
                | SDL_RENDERER_ACCELERATED,
            int32_t graphics_diriver_index = -1
        );

        void running(const ApplicationLoopInfo &info);

        void set_window_title(const std::string &title);
        void set_window_pos(const Point<int32_t> &pos);
        void set_window_size(const Size<int32_t> &size);
        void set_window_minimum_size(const Size<int32_t> &size);
        void set_window_maximum_size(const Size<int32_t> &size);

        std::string get_window_title() const;
        Point<int32_t> get_window_pos() const;
        Size<int32_t> get_window_size() const;
        Size<int32_t> get_window_minimum_size() const;
        Size<int32_t> get_window_maximum_size() const;

        [[nodiscard]] SDL_Window *get_window() const;
        [[nodiscard]] SDL_Renderer *get_renderer() const;
    };
}

#endif // ENGINE_CORE_APPLICATION_H_