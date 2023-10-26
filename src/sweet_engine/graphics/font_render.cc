#include "font_render.h"

namespace sweet {
    std::array<char, 2> FontRender::_split_char = { '\n', '\r' };

    FontRender::FontRender(
        SDL_Renderer *renderer,
        FontInfo info,
        const std::string &font,
        const std::string &text
    ) {
        _renderer = renderer;
        _info = info;
        _font = font;
        _text = text;

        alignment = FontAlignment::left;

        update_text();
    }

    std::vector<std::string> FontRender::split_line() {
        std::string buffer {};
        std::vector<std::string> lines {};

        for(const auto &text : _text) {
            for(const auto &split : _split_char) {
                if(text == split) {
                    lines.push_back(buffer);
                    buffer.clear();
                    break;
                } else {
                    buffer += text;
                    break;
                }
            }
        }

        lines.push_back(buffer);

        return lines;
    }

    void FontRender::update_text() {
        _lines.clear();

        std::vector<std::string> lines = split_line();
        for(const auto &line : lines)
            _lines.push_back({ _renderer, _info, _font, line });
    }

    void FontRender::render(float x, float y) {
        float pos_x = 0.0f;
        float pos_y = 0.0f;

        for(const auto &line : _lines) {
            switch(alignment) {
                case FontAlignment::left: {
                    pos_x = 0.0f;
                    break;
                };
                case FontAlignment::center: {
                    Size<uint32_t> size = get_size();
                    pos_x = (size.width - line.get_sprite()->get_width()) / 2.0f;
                    break;
                }
                case FontAlignment::right: {
                    Size<uint32_t> size = get_size();
                    pos_x = size.width - line.get_sprite()->get_width();
                    break;
                }
                default: {
                    pos_x = 0.0f;
                    break;
                }
            }

            line.get_sprite()->render(x + pos_x, y + pos_y);

            pos_y += line.get_sprite()->get_height() + _info.line_space;
        }
    }

    void FontRender::set_font_info(FontInfo info) {
        if(_info == info)
            return;

        _info = info;
        update_text();
    }

    void FontRender::set_font(const std::string &font) {
        if(_font == font)
            return;

        _font = font;
        update_text();
    }

    void FontRender::set_text(const std::string &text) {
        if(_text == text)
            return;

        _text = text;
        update_text();
    }

    Size<uint32_t> FontRender::get_size() const {
        Size<uint32_t> size { 0, 0 };

        for(const auto &line : _lines) {
            if(size.width < line.get_sprite()->get_width())
                size.width = line.get_sprite()->get_width();

            size.height += line.get_sprite()->get_height();
        }

        return size;
    }

    FontInfo FontRender::get_font_info() const {
        return _info;
    }

    std::string FontRender::get_font() const {
        return _font;
    }

    std::string FontRender::get_text() const {
        return _text;
    }
}