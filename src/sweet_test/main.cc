#include <application.h>
#include <application_loop_info.h>

static sweet::Application* app = nullptr;

int main(int args, char** argc) {
    sweet::ApplicationLoopInfo info {
    };

    app = new sweet::Application(
        "window",
        {SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED},
        {1280, 720}
    );

    app->running(info);
}