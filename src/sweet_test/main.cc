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

sweet::Sprite* img = nullptr;

void inited(sweet::Application& app) {
    sweet::FontInfo info {
        .color = SW_COLOR_WHITE
    };

    img = new sweet::Sprite(
        app.get_renderer(),
        "/Users/toha/Desktop/icon.png"
    );
}

void update(sweet::Application& app) {
    game_loop.update();
}

void render(sweet::Application& app) {
    sweet::Rectangle<int> rect {
        100,
        0,
        img->get_width(),
        img->get_height()
    };

    // Spriteの描画
    img->render(0, 0, rect);
}

void event(sweet::Application& app, SDL_Event& e) {
    sweet::Keyboard::update_event(e);
}

void finishing(sweet::Application &app) {
    // Spriteの破棄
    delete img;
}

int main(int args, char** argc) {
    std::filesystem::path current_path = std::filesystem::path(argc[0]);
    sweet::Logger::init_log(current_path.parent_path().string() + "/log.txt");

    SW_LOG_FATAL("Test Message");
    SW_LOG_ERROR("Test Message");
    SW_LOG_WARN("Test Message");

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
        {SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED},
        {1280, 720},
        window_flags,
        renderer_flags
    );

    game_loop.set_max_framerate(60.0f);
    app->running(info);

    delete app;

    return 0;
}