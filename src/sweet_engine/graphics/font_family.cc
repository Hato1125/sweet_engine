#include "font_family.h"

namespace sweet {
    bool FontFamily::operator==(const FontFamily &family) const {
        return font_color == family.font_color
            && font_info.font == family.font_info.font
            && font_info.style == family.font_info.style
            && font_info.hintting == family.font_info.hintting
            && font_size == family.font_size
            && text_space == family.text_space
            && line_space == family.line_space;
    }

    bool FontFamily::operator!=(const FontFamily &family) const {
        return font_color != family.font_color
            || font_info.font != family.font_info.font
            || font_info.style != family.font_info.style
            || font_info.hintting != family.font_info.hintting
            || font_size != family.font_size
            || text_space != family.text_space
            || line_space != family.line_space;
    }
}