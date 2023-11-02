#ifndef ENGINE_GRAPHICS_FONT_H_
#define ENGINE_GRAPHICS_FONT_H_

#include <memory>
#include <string>
#include <cstdint>

#include <SDL.h>
#include <SDL_ttf.h>

#include "sprite.h"
#include "font_info.h"

namespace sweet {
    class Font {
    private:
        static std::shared_ptr<Sprite> _empty_sprite_font;

    private:
        SDL_Renderer *_renderer;

        FontInfo _info;
        std::string _text;
        std::shared_ptr<Sprite> _sprite;

        SDL_Surface* create_font_surface();
        void update_font_sprite();

    public:
        Font(
            SDL_Renderer *renderer,
            FontInfo info = {},
            const std::string &text = ""
        );

        void set_font_info(FontInfo info);
        void set_text(const std::string &text);

        FontInfo get_font_info() const;
        std::string get_text() const;
        std::shared_ptr<Sprite> get_sprite() const;
    };
}

#endif // ENGINE_GRAPHICS_FONT_H_