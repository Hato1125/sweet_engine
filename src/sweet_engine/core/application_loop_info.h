#ifndef ENGINE_CORE_APPLICATION_LOOP_INFO_H_
#define ENGINE_CORE_APPLICATION_LOOP_INFO_H_

#include "SDL.h"

namespace sweet {
    class Application;
    struct ApplicationLoopInfo {
        void (*on_initing)(Application&) {nullptr};
        void (*on_inited)(Application&) {nullptr};
        void (*on_loop)(Application&) {nullptr};
        void (*on_finishing)(Application&) {nullptr};
        void (*on_finished)(Application&) {nullptr};
        void (*on_event)(Application&, SDL_Event&) {nullptr};
    };
}

#endif // ENGINE_CORE_APPLICATION_LOOP_INFO_H_