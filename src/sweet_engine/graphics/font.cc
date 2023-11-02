#include "font.h"

namespace sweet {
    std::shared_ptr<Sprite> Font::_empty_sprite_font = std::make_shared<Sprite>();

    Font::Font(
        SDL_Renderer *renderer,
        FontFamily family,
        const std::string &text
    ) {
        _renderer = renderer;
        _family = family;
        _text = text;

        update_font_sprite();
    }

    SDL_Surface* Font::create_font_surface() {
        TTF_Font *font = TTF_OpenFont(
            _family.font_info.font.c_str(),
            _family.font_size
        );

        if(font == nullptr)
            return nullptr;

        TTF_SetFontKerning(font, _family.text_space);
        TTF_SetFontStyle(font, static_cast<int>(_family.font_info.style));
        TTF_SetFontHinting(font, static_cast<int>(_family.font_info.hintting));

        SDL_Color color = { 
            _family.font_color.r,
            _family.font_color.g,
            _family.font_color.b
        };
        SDL_Surface *surface =  TTF_RenderUTF8_Blended(font, _text.c_str(), color);

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

    void Font::set_font_family(FontFamily family) {
        if(_family == family)
            return;

        _family = family;
        update_font_sprite();
    }

    void Font::set_text(const std::string &text) {
        if(_text == text)
            return;

        _text = text;
        update_font_sprite();
    }

    FontFamily Font::get_font_family() const {
        return _family;
    }

    std::string Font::get_text() const {
        return _text;
    }

    std::shared_ptr<Sprite> Font::get_sprite() const {
        return _sprite.get() == nullptr ? _empty_sprite_font : _sprite;
    }
}