#ifndef ENGINE_CORE_WINDOW_VISIT_STATE_H_
#define ENGINE_CORE_WINDOW_VISIT_STATE_H_

#include <SDL_video.h>

namespace sweet {
    enum class WindowVisitState {
        shown = SDL_WINDOW_SHOWN,
        hidden = SDL_WINDOW_HIDDEN
    };
}

#endif // ENGINE_CORE_WINDOW_VISIT_STATE_H_
