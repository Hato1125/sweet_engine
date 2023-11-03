#include "font_render.h"

namespace sweet {
    std::array<char, 2> FontRender::_split_char = { '\n', '\r' };

    FontRender::FontRender(
        SDL_Renderer *renderer,
        FontInfo info,
        const std::string &text
    ) {
        _renderer = renderer;
        _info = info;
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
        const auto texts = split_line();
        const size_t text_length = texts.size();
        const size_t line_length = _lines.size();

        // もし更新する文字列の行より現在の行の方が多い場合は、その差分消す
        if(text_length < line_length) {
            const size_t diff_length = line_length - text_length;
            for(int i = 0; i < diff_length; ++i)
                _lines.pop_back();
        }

        for(int i = 0; i < text_length; ++i) {
            // iが現在の行より小さければ更新できるかを確認する
            if(i < line_length) {
                if(_lines[i]->get_text() != texts[i])
                    _lines[i].reset(new Font(_renderer, _info, texts[i]));
            } else {
                _lines.push_back(std::make_unique<Font>(_renderer, _info, texts[i]));
            }
        }

        /*
        _lines.clear();

        for(const auto &line : lines)
            _lines.push_back(std::make_unique<Font>(_renderer, _info, line));

        */

        calc_font_size();
    }

    void FontRender::calc_font_size() {
        for(const auto &line : _lines) {
            const auto &sprite = line->get_sprite();

            if(_size.width < sprite->get_width())
                _size.width = sprite->get_width();

            _size.height += sprite->get_height();
        }
    }

    void FontRender::render(float x, float y) {
        float pos_x = 0.0f;
        float pos_y = 0.0f;

        for(const auto &line : _lines) {
            auto font_sprite = line->get_sprite();

            switch(alignment) {
                case FontAlignment::left: {
                    pos_x = 0.0f;
                    break;
                }
                case FontAlignment::center: {
                    Size<uint32_t> size = get_size();
                    pos_x = (size.width - font_sprite->get_width()) / 2.0f;
                    break;
                }
                case FontAlignment::right: {
                    Size<uint32_t> size = get_size();
                    pos_x = size.width - font_sprite->get_width();
                    break;
                }
                default: {
                    pos_x = 0.0f;
                    break;
                }
            }

            font_sprite->render(x + pos_x, y + pos_y);

            pos_y += font_sprite->get_height() + _info.line_space;
        }
    }

    void FontRender::set_font_info(FontInfo info) {
        if(_info == info)
            return;

        _info = info;
        update_text();
    }

    void FontRender::set_text(const std::string &text) {
        if(_text == text)
            return;

        _text = text;
        update_text();
    }

    Size<uint32_t> FontRender::get_size() const {
        return _size;
    }

    FontInfo FontRender::get_font_info() const {
        return _info;
    }

    std::string FontRender::get_text() const {
        return _text;
    }
}