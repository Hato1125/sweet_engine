#include "font_info.h"

namespace sweet {
    bool FontInfo::operator ==(const FontInfo &info) const {
        return color == info.color && style == info.style
            && hinting == info.hinting && point == info.point;
    }

    bool FontInfo::operator !=(const FontInfo &info) const {
        return color != info.color || style != info.style
            && hinting != info.hinting || point != info.point;
    }
}