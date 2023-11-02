#ifndef ENGINE_GRAPHICS_FONT_H_
#define ENGINE_GRAPHICS_FONT_H_

#include <memory>
#include <string>
#include <cstdint>

#include <SDL.h>
#include <SDL_ttf.h>

#include "sprite.h"
#include "font_family.h"

namespace sweet {
    class Font {
    private:
        static std::shared_ptr<Sprite> _empty_sprite_font;

    private:
        SDL_Renderer *_renderer;

        FontFamily _family;
        std::string _text;
        std::shared_ptr<Sprite> _sprite;

        SDL_Surface* create_font_surface();
        void update_font_sprite();

    public:
        Font(
            SDL_Renderer *renderer,
            FontFamily family = {},
            const std::string &text = ""
        );

        void set_font_family(FontFamily family);
        void set_text(const std::string &text);

        FontFamily get_font_family() const;
        std::string get_text() const;
        std::shared_ptr<Sprite> get_sprite() const;
    };
}

#endif // ENGINE_GRAPHICS_FONT_H_