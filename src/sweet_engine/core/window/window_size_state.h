#ifndef ENGINE_CORE_WINDOW_WINDOW_SIZE_STATE_H_
#define ENGINE_CORE_WINDOW_WINDOW_SIZE_STATE_H_

#include <SDL_video.h>

namespace sweet {
    enum class WindowSizeState {
        minimized = SDL_WINDOW_MINIMIZED,
        maximized = SDL_WINDOW_MAXIMIZED,
        fullscreen = SDL_WINDOW_FULLSCREEN,
        fullscreen_desktop = SDL_WINDOW_FULLSCREEN_DESKTOP
    };
}

#endif // ENGINE_CORE_WINDOW_WINDOW_SIZE_STATE_H_
