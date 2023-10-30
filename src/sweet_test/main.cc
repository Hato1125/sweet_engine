#include <font_render.h>
#include <sprite.h>
#include <keyboard.h>
#include <game_loop.h>
#include <application.h>
#include <color.h>
#include <application_loop_info.h>
#include <logger.h>

#include <memory>
#include <iostream>
#include <thread>

#undef main

static sweet::Application *app = nullptr;
static sweet::GameLoop game_loop = {};

static std::unique_ptr<sweet::FontRender> debug_text;

void inited(sweet::Application& app) {
    const sweet::FontInfo font_info {
        .point = 25,
        .style = sweet::FontStyle::italic,
    };

    const std::string font_name = "/Library/Fonts/SF-Mono-Heavy.otf";

    debug_text = std::make_unique<sweet::FontRender>(
        app.get_renderer(),
        font_info,
        font_name,
        "Frame ms:\nDelta ms:\nFramerate:"
    );
}

void begin_frame(sweet::Application &app) {
    game_loop.begin_update();
}

void end_frame(sweet::Application &app) {
    game_loop.end_update();
}

void update(sweet::Application& app) {
    std::stringstream debug_message;

    debug_message
        << "Frame ms:   " << std::to_string(game_loop.get_frame_sec()) << "\n"
        << "Delta ms:   " << std::to_string(game_loop.get_delta_sec()) << "\n"
        << "Framerate:  " << std::to_string(game_loop.get_framerate());

    debug_text->set_text(debug_message.str());
}

void render(sweet::Application& app) {
    debug_text->render(0, 0);
}

void event(sweet::Application& app, SDL_Event& e) {
}

void finishing(sweet::Application &app) {
}

int main(int args, char** argc) {
    std::filesystem::path current_path = std::filesystem::path(argc[0]);
    sweet::Logger::init_log(current_path.parent_path().string() + "/log.txt");

    sweet::ApplicationLoopInfo info {
        .on_inited = inited,
        .on_update = update,
        .on_render = render,
        .on_event = event,
        .on_finishing = finishing,
        .on_begin_frame = begin_frame,
        .on_end_frame = end_frame
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

    //game_loop.set_max_framerate(60.0);
    app->running(info);

    delete app;

    return 0;
}