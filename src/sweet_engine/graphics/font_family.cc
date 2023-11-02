#include "font_family.h"

namespace sweet {
    bool FontFamily::operator ==(const FontFamily &family) const {
        return font == family.font
            && style == family.style
            && hintting == family.hintting;
    }

    bool FontFamily::operator !=(const FontFamily &family) const {
        return font != family.font
            || style != family.style
            || hintting != family.hintting;
    }
}