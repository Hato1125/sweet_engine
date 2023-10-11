#include "font_info.h"

namespace sweet {
    FontInfo::FontInfo() {
        color = {255, 255, 255};
        style = FontStyle::normal;
        hinting = FontHinting::normal;
        point = 20;
        text_space = 0;
        line_space = 0;
    }

    bool FontInfo::operator ==(const FontInfo &info) const {
        return color == info.color && style == info.style
            && hinting == info.hinting && point == info.point;
    }

    bool FontInfo::operator !=(const FontInfo &info) const {
        return color != info.color || style != info.style
            && hinting != info.hinting || point != info.point;
    }
}