#include "font_test.h"

namespace swtest {
    void FontTest::impl_init() {
        const std::string one_line_text = "Hello World!";
        const std::string mul_line_text = "Hello World!\nHello World!\nHello World!\nHello World!\nHello World!\n";
        const std::string font_path = "/Library/Fonts/SF-Pro-Rounded-Bold.otf";

        const sweet::FontFamily font_family {
            .font_info = {
                .font = font_path,
                .style = sweet::FontStyle::italic
            },
            .font_size = 25,
            .text_space = 1,
            .line_space = 1
        };

        _font = std::make_unique<sweet::Font>(
            Main::k_application->get_renderer(),
            font_family,
            one_line_text
        );

        _font_render = std::make_unique<sweet::FontRender>(
            Main::k_application->get_renderer(),
            font_family,
            mul_line_text
        );
    }

    void FontTest::impl_render() {
        _font->get_sprite()->render(0, 0);
        _font_render->render(0, _font->get_sprite()->get_height() * 2.0f);
    }
}