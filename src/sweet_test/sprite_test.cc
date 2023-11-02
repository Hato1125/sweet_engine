#include "sprite_test.h"

namespace swtest {
    void SpriteTest::impl_init() {
        _sprite = std::make_unique<sweet::Sprite>(
            Main::k_application->get_renderer(),
            "/Users/toha/Pictures/2-1.png"
        );

        _sprite->horizontal_scale = 3.0f;
        _sprite->vertical_scale = 3.0f;
        _sprite->renderer_h_pos = sweet::HorizontalPoint::center;
        _sprite->renderer_v_pos = sweet::VerticalPoint::center;
    }

    void SpriteTest::impl_render() {
        auto win_size = Main::k_application->get_window_size();

        _sprite->render(
            win_size.width / 2.0f,
            win_size.height / 2.0f
        );
    }
}