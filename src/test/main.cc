#include <application.h>
#include <application_loop_config.h>

static sweet::Application* app = nullptr;

void loop(sweet::Application& app) {
    SDL_SetRenderDrawColor(app.get_renderer(), 255, 255, 255, 255);
    SDL_RenderDrawPoint(app.get_renderer(), 10, 10);
    SDL_SetRenderDrawColor(app.get_renderer(), 0, 0, 0, 255);
}

int main(int args, char** argc) {
    sweet::ApplicationLoopInfo info {
        .on_loop = loop
    };

    app = new sweet::Application(
        "window",
        {SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED},
        {1280, 720}
    );

    app->running(info);
}