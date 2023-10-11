#include "font_render.h"

namespace sweet {
    std::array<char, 2> FontRender::_split_char = {'\n', '\r'};

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

        for(int i = 0; i < _text.size(); i++) {
            for(int j = 0; j < _split_char.size(); j++) {
                if(_text[i] == _split_char[j]) {
                    lines.push_back(buffer);
                    buffer.clear();
                    break;
                } else {
                    buffer += _text[i];
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
        for(int i = 0; i < lines.size(); i++)
            _lines.push_back({_renderer, _info, _font, lines[i]});
    }

    void FontRender::render(float x, float y) {
        float pos_x = 0.0f;
        float pos_y = 0.0f;

        for(int i = 0; i < _lines.size(); i++) {
            switch(alignment) {
                case FontAlignment::left: {
                    pos_x = 0.0f;
                    break;
                };

                case FontAlignment::center: {
                    Size<uint32_t> size = get_size();
                    pos_x = (size.width - _lines[i].get_sprite()->get_width()) / 2.0f;
                    break;
                }

                case FontAlignment::right: {
                    Size<uint32_t> size = get_size();
                    pos_x = size.width - _lines[i].get_sprite()->get_width();
                    break;
                }

                default: {
                    pos_x = 0.0f;
                    break;
                }
            }

            _lines[i].get_sprite()->render(x + pos_x, y + pos_y);

            pos_y += _lines[i].get_sprite()->get_height() + _info.line_space;
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
        Size<uint32_t> size {0, 0};

        for(int i = 0; i < _lines.size(); i++) {
            if(size.width < _lines[i].get_sprite()->get_width()) {
                size.width = _lines[i].get_sprite()->get_width();
            }

            if(size.height < _lines[i].get_sprite()->get_height())
                size.height = _lines[i].get_sprite()->get_height();
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