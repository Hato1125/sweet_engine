#include "font_info.h"

namespace sweet {
    bool FontInfo::operator ==(const FontInfo &info) const {
        return font_family == info.font_family
            && font_color == info.font_color
            && font_size == info.font_size
            && text_space == info.text_space
            && line_space == info.line_space;
    }

    bool FontInfo::operator !=(const FontInfo &info) const {
        return font_family != info.font_family
            || font_color != info.font_color
            || font_size != info.font_size
            || text_space != info.text_space
            || line_space != info.line_space;
    }
}