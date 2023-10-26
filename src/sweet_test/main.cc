#include <font_render.h>
#include <sprite.h>
#include <keyboard.h>
#include <game_loop.h>
#include <application.h>
#include <color.h>
#include <application_loop_info.h>
#include <logger.h>

#include <iostream>

#undef main

static sweet::Application *app = nullptr;
static sweet::GameLoop game_loop = {};

static sweet::FontRender *font = nullptr;

void inited(sweet::Application& app) {
    sweet::FontInfo info = {
        .point = 100,
    };
    font = new sweet::FontRender(
        app.get_renderer(),
        info,
        "/Library/Fonts/SF-Compact-Rounded-Black.otf",
        "Akasoko\nAosoko\nPinksoko"
    );

    std::cout << font->get_size().height << std::endl;
}

void update(sweet::Application& app) {
    game_loop.update();
}

void render(sweet::Application& app) {
    font->render(0, 0);
}

void event(sweet::Application& app, SDL_Event& e) {
    sweet::Keyboard::update_event(e);
}

void finishing(sweet::Application &app) {
    delete font;
}

int main(int args, char** argc) {
    std::filesystem::path current_path = std::filesystem::path(argc[0]);
    sweet::Logger::init_log(current_path.parent_path().string() + "/log.txt");

    sweet::ApplicationLoopInfo info {
        .on_inited = inited,
        .on_update = update,
        .on_render = render,
        .on_event = event,
        .on_finishing = finishing
    };

    uint32_t window_flags = SDL_WINDOW_SHOWN;
    uint32_t renderer_flags = SDL_RENDERER_ACCELERATED
        | SDL_RENDERER_TARGETTEXTURE;

    app = new sweet::Application(
        "window",
        { SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED },
        { 1280, 720 },
        window_flags,
        renderer_flags
    );

    game_loop.set_max_framerate(60.0f);
    app->running(info);

    delete app;

    return 0;
}