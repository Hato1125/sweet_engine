#include "application.h"

namespace sweet {
    Application::Application(
        const std::string& title,
        const std::pair<uint32_t, uint32_t>& pos,
        const std::pair<uint32_t, uint32_t>& size,
        uint32_t window_flags,
        uint32_t renderer_flags,
        int32_t graphics_device_index
    ) : _window(nullptr, SDL_DestroyWindow),
        _renderer(nullptr, SDL_DestroyRenderer) {
        is_running = false;
        is_auto_finish = true;

        SDL_Window* wind = nullptr;
        SDL_Renderer* rend = nullptr;

        wind = SDL_CreateWindow(
            title.c_str(),
            std::get<0>(pos),
            std::get<1>(pos),
            std::get<0>(size),
            std::get<1>(size),
            window_flags
        );

        if(wind != nullptr) {
            rend = SDL_CreateRenderer(
                wind,
                graphics_device_index,
                renderer_flags
            );

            if(rend == nullptr) {
                SDL_DestroyWindow(wind);
            } else {
                _window.reset(wind);
                _renderer.reset(rend);
            }
        }
    }

    void Application::running(const ApplicationLoopInfo& info) {
        if(info.on_initing != nullptr)
            info.on_initing(*this);

        if(SDL_Init(SDL_INIT_EVERYTHING) < 0
            || _window.get() == nullptr
            || _renderer.get() == nullptr)
            return;

        if(info.on_inited != nullptr)
            info.on_inited(*this);

        SDL_Event event {};
        is_running = true;

        while(is_running) {
            while(SDL_PollEvent(&event)) {
                if(event.type == SDL_QUIT && is_auto_finish)
                    goto LOOP_FINISH;

                if(info.on_event != nullptr)
                    info.on_event(*this, event);
            }

            SDL_SetRenderDrawColor(_renderer.get(), 255, 0, 255, 255);
            SDL_RenderClear(_renderer.get());

            if(info.on_loop != nullptr)
                info.on_loop(*this);

            SDL_RenderPresent(_renderer.get());
        }

        LOOP_FINISH:

        if(info.on_finishing != nullptr)
            info.on_finishing(*this);

        SDL_Quit();

        if(info.on_finished != nullptr)
            info.on_finished(*this);
    }

    void Application::set_window_title(const std::string& title) {
        SDL_SetWindowTitle(_window.get(), title.c_str());
    }

    void Application::set_window_pos(const std::pair<uint32_t, uint32_t>& pos) {
        SDL_SetWindowPosition(_window.get(), std::get<0>(pos), std::get<1>(pos));
    }

    void Application::set_window_size(const std::pair<uint32_t, uint32_t>& size) {
        SDL_SetWindowSize(_window.get(), std::get<0>(size), std::get<1>(size));
    }

    void Application::set_window_minimum_size(const std::pair<uint32_t, uint32_t>& size) {
        SDL_SetWindowMinimumSize(_window.get(), std::get<0>(size), std::get<1>(size));
    }

    void Application::set_window_maximum_size(const std::pair<uint32_t, uint32_t>& size) {
        SDL_SetWindowMaximumSize(_window.get(), std::get<0>(size), std::get<1>(size));
    }

    std::string Application::get_window_title() const {
        return SDL_GetWindowTitle(_window.get());
    }

    std::pair<uint32_t, uint32_t> Application::get_window_pos() const {
        int x = 0;
        int y = 0;

        SDL_GetWindowPosition(_window.get(), &x, &y);

        return {x, y};
    }

    std::pair<uint32_t, uint32_t> Application::get_window_size() const {
        int width = 0;
        int height = 0;

        SDL_GetWindowSize(_window.get(), &width, &height);

        return {width, height};
    }

    std::pair<uint32_t, uint32_t> Application::get_window_minimum_size() const {
        int width = 0;
        int height = 0;

        SDL_GetWindowMinimumSize(_window.get(), &width, &height);

        return {width, height};
    }

    std::pair<uint32_t, uint32_t> Application::get_window_maximum_size() const {
        int width = 0;
        int height = 0;

        SDL_GetWindowMaximumSize(_window.get(), &width, &height);

        return {width, height};
    }

    SDL_Window* Application::get_window() const {
        return _window.get();
    }

    SDL_Renderer* Application::get_renderer() const {
        return _renderer.get();
    }
}