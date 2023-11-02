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

    struct FontInfo {
        std::string font { "none" };
        FontStyle style { FontStyle::normal };
        FontHintting hintting { FontHintting::normal };
    };

    struct FontFamily {
        FontInfo font_info { };
        Color font_color { SW_COLOR_WHITE };
        int32_t font_size { 0 };
        int32_t text_space { 0 };
        int32_t line_space { 0 };

        bool operator ==(const FontFamily &family) const;
        bool operator !=(const FontFamily &family) const;
    };
}

#endif // ENGINE_FONT_FAMILY_H_