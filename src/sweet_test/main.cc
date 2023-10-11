#include <font_render.h>
#include <sprite.h>
#include <keyboard.h>
#include <game_loop.h>
#include <application.h>
#include <application_loop_info.h>

#include <iostream>

static sweet::Sprite *sprt = nullptr;
static sweet::FontRender *font = nullptr;
static sweet::Application *app = nullptr;
static sweet::GameLoop game_loop = {};

void inited(sweet::Application& app) {
    sprt = new sweet::Sprite(app.get_renderer(), "/Users/toha/Desktop/macOS-Graphic.jpeg");
    sprt->horizontal_scale = 0.07f;
    sprt->vertical_scale = 0.07f;
    sprt->renderer_h_pos = sweet::HorizontalPoint::center;
    sprt->renderer_v_pos = sweet::VerticalPoint::center;

    sweet::FontInfo info {};
    info.color = sweet::Color(255, 255, 255);
    info.point = 60;
    font = new sweet::FontRender(app.get_renderer(), info, "/Users/toha/Desktop/Roboto-MediumItalic.ttf", "Hello World\nKaigyouTest1\nKaigyouTest2");
    font->alignment = sweet::FontAlignment::center;
}

void update(sweet::Application& app) {
    game_loop.update();
    sweet::Keyboard::update();
}

void render(sweet::Application& app) {
    //sprt->render(1280 / 2, 720 / 2);
    font->render(480, 180);
}

void event(sweet::Application& app, SDL_Event& e) {
    sweet::Keyboard::update_event(e);
}

int main(int args, char** argc) {
    sweet::ApplicationLoopInfo info {
        .on_inited = inited,
        .on_update = update,
        .on_render = render,
        .on_event = event,
    };

    app = new sweet::Application(
        "window",
        {SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED},
        {1280, 720}
    );

    game_loop.set_max_framerate(60.0f);
    app->running(info);

    delete sprt;
    delete app;
}