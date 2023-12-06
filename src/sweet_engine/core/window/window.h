#ifndef ENGINE_CORE_WINDOW_WINDOW_H_
#define ENGINE_CORE_WINDOW_WINDOW_H_

#include <string>
#include <memory>
#include <cstdint>
#include <expected>
#include <filesystem>

#include <SDL.h>

#include <point.h>
#include <size.h>

#include "window_init_opts.h"

namespace sweet {
    class Window {
    public:
        std::expected<void, std::string>init(
            const WindowInitOpts &opts
        ) noexcept;
        
        Window &set_title(const std::string &title) noexcept;
        Window &set_pos(const Point<int32_t> &pos) noexcept;
        Window &set_size(const Size<uint32_t> &size) noexcept;
        Window &set_min_size(const Size<uint32_t> &size) noexcept;
        Window &set_max_size(const Size<uint32_t> &size) noexcept;

        std::string get_title() const noexcept;
        Point<int32_t> get_pos() const noexcept;
        Size<uint32_t> get_size() const noexcept;
        Size<uint32_t> get_min_size() const noexcept;
        Size<uint32_t> get_max_size() const noexcept;

        [[nodiscard]]
        SDL_Window *get_sdl_window() const noexcept;

    private:
        std::unique_ptr<SDL_Window, decltype(&SDL_DestroyWindow)> _window {
            nullptr,
            SDL_DestroyWindow
        };
    };
}

#endif // ENGINE_CORE_WINDOW_WINDOW_H_
