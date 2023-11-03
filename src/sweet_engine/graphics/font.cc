#include "font.h"

namespace sweet {
    std::shared_ptr<Sprite> Font::_empty_sprite_font = std::make_shared<Sprite>();

    Font::Font(
        SDL_Renderer *renderer,
        FontInfo info,
        const std::string &text
    ) {
        _renderer = renderer;
        _info = info;
        _text = text;

        update_font_sprite();
    }

    SDL_Surface* Font::create_font_surface() {
        TTF_Font *font = TTF_OpenFont(
            _info.font_family.font.c_str(),
            _info.font_size
        );

        if(font == nullptr)
            return nullptr;

        TTF_SetFontKerning(font, _info.text_space);
        TTF_SetFontStyle(font, static_cast<int>(_info.font_family.style));
        TTF_SetFontHinting(font, static_cast<int>(_info.font_family.hintting));

        SDL_Color color = { 
            _info.font_color.r,
            _info.font_color.g,
            _info.font_color.b
        };

        SDL_Surface *surface = TTF_RenderUTF8_Blended(font, _text.c_str(), color);

        TTF_CloseFont(font);

        return surface;
    }

    void Font::update_font_sprite() {
        if(_renderer == nullptr)
            return;

        SDL_Surface *surface = create_font_surface();
        if(surface == nullptr)
            return;

        _sprite.reset(new Sprite(_renderer, surface));
    }

    void Font::set_font_info(FontInfo info) {
        if(_info == info)
            return;

        _info = info;
        update_font_sprite();
    }

    void Font::set_text(const std::string &text) {
        if(_text == text)
            return;

        _text = text;
        update_font_sprite();
    }

    FontInfo Font::get_font_info() const {
        return _info;
    }

    std::string Font::get_text() const {
        return _text;
    }

    std::shared_ptr<Sprite> Font::get_sprite() const {
        return _sprite.get() == nullptr ? _empty_sprite_font : _sprite;
    }
}