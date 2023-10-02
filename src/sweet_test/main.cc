#include <sprite.h>
#include <application.h>
#include <application_loop_info.h>

static sweet::Sprite *sprt = nullptr;
static sweet::Application *app = nullptr;

void inited(sweet::Application& app) {
    sprt = new sweet::Sprite(app.get_renderer(), "/Users/toha/Desktop/macOS-Graphic.jpeg");
    sprt->horizontal_scale = 0.07f;
    sprt->vertical_scale = 0.07f;
    sprt->renderer_h_pos = sweet::HorizontalPoint::center;
    sprt->renderer_v_pos = sweet::VerticalPoint::center;
}

void loop(sweet::Application& app) {
    sprt->render(1280 / 2, 720 / 2);
}

int main(int args, char** argc) {
    sweet::ApplicationLoopInfo info {
        .on_inited = inited,
        .on_loop = loop,
    };

    app = new sweet::Application(
        "window",
        {SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED},
        {1280, 720}
    );

    app->running(info);

    delete sprt;
    delete app;
}