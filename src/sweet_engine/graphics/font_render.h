#ifndef ENGINE_GRAPHICS_FONT_RENDER_H_
#define ENGINE_GRAPHICS_FONT_RENDER_H_

#include <array>
#include <vector>
#include <string>
#include <memory>
#include <cstdint>

#include <SDL.h>

#include <size.h>

#include "font.h"

namespace sweet {
    enum class FontAlignment {
        left,
        center,
        right
    };

    class FontRender {
    private:
        static std::array<char, 2> _split_char;

    private:
        SDL_Renderer *_renderer;

        FontInfo _info;
        Size<uint32_t> _size;
        std::string _text;
        std::vector<std::unique_ptr<Font>> _lines;

        std::vector<std::string> split_line();
        void update_text();
        void calc_font_size();

    public:
        FontAlignment alignment;

        FontRender(
            SDL_Renderer *renderer,
            FontInfo info = {},
            const std::string &text = ""
        );

        void render(float x, float y);

        void set_font_info(FontInfo info);
        void set_text(const std::string &text);

        Size<uint32_t> get_size() const;
        FontInfo get_font_info() const;
        std::string get_text() const;
    };
}

#endif // ENGINE_GRAPHICS_FONT_RENDER_H_