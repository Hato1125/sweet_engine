#ifndef ENGINE_GRAPHICS_FONT_INFO_H_
#define ENGINE_GRAPHICS_FONT_INFO_H_

#include <cstdint>

#include <color.h>

#include "font_family.h"

namespace sweet {
    struct FontInfo {
        FontFamily font_family {};
        Color font_color { SW_COLOR_WHITE };
        int32_t font_size { 20 };
        int32_t text_space { 0 };
        int32_t line_space { 0 };

        bool operator ==(const FontInfo &info) const;
        bool operator !=(const FontInfo &info) const;
    };
}

#endif // ENGINE_GRAPHICS_FONT_INFO_H_