#ifndef ENGINE_CORE_WINDOW_WINDOW_INIT_OPTS_H_
#define ENGINE_CORE_WINDOW_WINDOW_INIT_OPTS_H_

#include <string>
#include <cstdint>

#include "window_visit_state.h"
#include "window_size_state.h"

#include <point.h>
#include <size.h>

namespace sweet {
    struct WindowInitOpts {
        WindowVisitState visit_state { WindowVisitState::shown };
        WindowSizeState size_state { WindowSizeState::minimized };

        std::string title { };

        Point<int32_t> position { };
        Size<uint32_t> size { };

        bool is_resizable { true };
        bool is_highdpi { true };
        bool is_utility { false };
        bool is_tooltip { false };
        bool is_skip_taskbar { false };
    };
}

#endif // ENGINE_CORE_WINDOW_WINDOW_INIT_OPTS_H_
