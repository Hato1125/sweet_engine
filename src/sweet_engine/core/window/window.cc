#include "window.h"

namespace sweet {
    std::expected<void, std::string> Window::init(
        const WindowInitOpts &opts
    ) noexcept {
        if(opts.size.width <= 0 || opts.size.height <= 0)
            return std::unexpected { "Please make the window size larger than 0." };

        uint32_t flags
            = static_cast<uint32_t>(opts.visit_state)
            | static_cast<uint32_t>(opts.size_state);

        if(opts.is_resizable) flags |= SDL_WINDOW_RESIZABLE;
        if(opts.is_highdpi) flags |= SDL_WINDOW_ALLOW_HIGHDPI;

#if WIN32
        if(opts.is_utility) flags |= SDL_WINDOW_UTILITY;
        if(opts.is_tooltip) flags |= SDL_WINDOW_TOOLTIP;
        if(opts.is_skip_taskbar) flags |= SDL_WINDOW_SKIP_TASKBAR;
#endif

        SDL_Window *window = SDL_CreateWindow(
            opts.title.c_str(),
            opts.position.x,
            opts.position.y,
            opts.size.width,
            opts.size.height,
            flags
        );

        if(window == nullptr)
            return std::unexpected { "Failed to create SDL_Window." };

        _window.reset(window);

        return { };
    }

    Window &Window::set_title(const std::string &title) noexcept {
        SDL_SetWindowTitle(_window.get(), title.c_str());
        return *this;
    }

    Window &Window::set_pos(const Point<int32_t> &pos) noexcept {
        SDL_SetWindowPosition(_window.get(), pos.x, pos.y);
        return *this;
    }

    Window &Window::set_size(const Size<uint32_t> &size) noexcept {
        SDL_SetWindowSize(
            _window.get(),
            static_cast<int32_t>(size.width),
            static_cast<int32_t>(size.height)
        );

        return *this;
    }

    Window &Window::set_min_size(const Size<uint32_t> &size) noexcept {
        SDL_SetWindowMinimumSize(
            _window.get(),
            static_cast<int32_t>(size.width),
            static_cast<int32_t>(size.height)
        );

        return *this;
    }

    Window &Window::set_max_size(const Size<uint32_t> &size) noexcept {
        SDL_SetWindowMaximumSize(
            _window.get(),
            static_cast<int32_t>(size.width),
            static_cast<int32_t>(size.height)
        );

        return *this;
    }

    std::string Window::get_title() const noexcept {
        return SDL_GetWindowTitle(_window.get());
    }

    Point<int32_t> Window::get_pos() const noexcept {
        int32_t x = 0;
        int32_t y = 0;

        SDL_GetWindowPosition(_window.get(), &x, &y);

        return { x, y };
    }

    Size<uint32_t> Window::get_size() const noexcept {
        int32_t width = 0;
        int32_t height = 0;

        SDL_GetWindowSize(_window.get(), &width, &height);

        return {
            static_cast<uint32_t>(width),
            static_cast<uint32_t>(height)
        };
    }

    Size<uint32_t> Window::get_min_size() const noexcept {
        int32_t width = 0;
        int32_t height = 0;

        SDL_GetWindowMinimumSize(_window.get(), &width, &height);

        return {
            static_cast<uint32_t>(width),
            static_cast<uint32_t>(height)
        };
    }

    Size<uint32_t> Window::get_max_size() const noexcept {
        int32_t width = 0;
        int32_t height = 0;

        SDL_GetWindowMaximumSize(_window.get(), &width, &height);

        return {
            static_cast<uint32_t>(width),
            static_cast<uint32_t>(height)
        };
    }

    SDL_Window *Window::get_sdl_window() const noexcept {
        return _window.get();
    }
}
