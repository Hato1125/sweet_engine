#ifndef ENGINE_FONT_FAMILY_H_
#define ENGINE_FONT_FAMILY_H_

#include <string>
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

    enum class FontHintting {
        normal = TTF_HINTING_NORMAL,
        light = TTF_HINTING_LIGHT,
        mono = TTF_HINTING_MONO,
        none = TTF_HINTING_NONE,
        ligth_subpixel = TTF_HINTING_LIGHT_SUBPIXEL
    };

    struct FontFamily {
        std::string font { "none" };
        FontStyle style { FontStyle::normal };
        FontHintting hintting { FontHintting::normal };

        bool operator ==(const FontFamily &family) const;
        bool operator !=(const FontFamily &family) const;
    };
}

#endif // ENGINE_FONT_FAMILY_H_