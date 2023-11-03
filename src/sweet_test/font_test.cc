#include "font_test.h"

namespace swtest {
    void FontTest::impl_init() {
        const std::string one_line_text = "Hello World!";
        const std::string mul_line_text = "Hello World!\nHello World!\nHello World!\nHello World!\nHello World!\nHello World!";
        const std::string font_path = "/Library/Fonts/SF-Pro-Rounded-Bold.otf";

        const sweet::FontInfo font_info {
            .font_family = {
                .font = font_path,
                .style = sweet::FontStyle::italic
            },
            .font_size = 25,
            .text_space = 1,
            .line_space = 1
        };

        _font = std::make_unique<sweet::Font>(
            Main::k_application->get_renderer(),
            font_info,
            one_line_text
        );

        _font_render = std::make_unique<sweet::FontRender>(
            Main::k_application->get_renderer(),
            font_info,
            mul_line_text
        );
    }

    void FontTest::impl_update() {
        std::stringstream text;

        text
            << "Framerate:" << std::to_string(Main::k_game_loop->get_framerate()) << "\n"
            << "Frame sec: " << std::to_string(Main::k_game_loop->get_frame_sec()) << "\n"
            << "Delta sec: " << std::to_string(Main::k_game_loop->get_delta_sec()) << "\n"
            << "Hello World!" << "\n"
            << "Hello World!" << "\n"
            << "Hello World!" << "\n"
            << "Hello World!" << "\n"
            << "Hello World!" << "\n"
            << "Hello World!" << "\n"
            << "Hello World!" << "\n"
            << "Hello World!" << "\n"
            << "Hello World!" << "\n"
            << "Hello World!" << "\n"
            << "Hello World!" << "\n"
            << "Hello World!" << "\n"
            << "Hello World!" << "\n"
            << "Hello World!" << "\n"
            << "Hello World!" << "\n"
            << "Hello World!" << "\n"
            << "Hello World!" << "\n"
            << "Hello World!" << "\n"
            << "Hello World!" << "\n"
            << "Hello World!" << "\n"
            << "Hello World!" << "\n"
            << "Hello World!" << "\n"
            << "Hello World!" << "\n"
            << "Hello World!" << "\n"
            << "Hello World!" << "\n"
            << "Hello World!" << "\n"
            << "Hello World!" << "\n"
            << "Hello World!" << "\n"
            << "Hello World!" << "\n"
            << "Hello World!" << "\n"
            << "Hello World!" << "\n"
            << "Hello World!" << "\n"
            << "Hello World!" << "\n"
            << "Hello World!" << "\n"
            << "Hello World!" << "\n"
            << "Hello World!" << "\n"
            << "Hello World!" << "\n";

        _font_render->set_text(text.str());
    }

    void FontTest::impl_render() {
        _font->get_sprite()->render(0, 0);
        _font_render->render(0, _font->get_sprite()->get_height() * 2.0f);
    }
}