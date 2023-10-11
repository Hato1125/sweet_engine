#ifndef ENGINE_GRAPHICS_FONT_INFO_H_
#define ENGINE_GRAPHICS_FONT_INFO_H_

#include <cstdint>

#include <SDL_ttf.h>

#include <color.h>

namespace sweet {
    enum class FontStyle {
        normal = TTF_STYLE_NORMAL,
        bold = TTF_STYLE_BOLD,
        italic = TTF_STYLE_ITALIC,
        underline = TTF_STYLE_UNDERLINE,
        strikethrough = TTF_STYLE_STRIKETHROUGH
    };

    enum class FontHinting {
        normal = TTF_HINTING_NORMAL,
        light = TTF_HINTING_LIGHT,
        mono = TTF_HINTING_MONO,
        none = TTF_HINTING_NONE,
        light_subpixel = TTF_HINTING_LIGHT_SUBPIXEL
    };

    struct FontInfo {
        FontInfo();

        Color color;
        FontStyle style;
        FontHinting hinting;
        uint32_t point;
        uint32_t text_space;
        uint32_t line_space;

        bool operator ==(const FontInfo &info) const;
        bool operator !=(const FontInfo &info) const;
    };
}

#endif // ENGINE_GRAPHICS_FONT_INFO_H_