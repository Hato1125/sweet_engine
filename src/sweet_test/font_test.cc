#include "font_test.h"

namespace swtest {
    void FontTest::impl_init() {
        const std::string text = "Hello World!";
        const std::string font_path = "/Library/Fonts/SF-Pro-Rounded-Bold.otf";

        const sweet::FontInfo font_info {
            .point = 25,
            .text_space = 2,
            .line_space = 2,
        };

        _font = std::make_unique<sweet::Font>(
            Main::k_application->get_renderer(),
            font_info,
            font_path,
            text
        );
    }

    void FontTest::impl_render() {
        _font->get_sprite()->render(0, 0);
    }
}