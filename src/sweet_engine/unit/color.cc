#include "color.h"

namespace sweet {
    Color::Color() {
        r = 0;
        g = 0;
        b = 0;
        a = 0;
    }

    Color::Color(uint8_t value) {
        r = value;
        g = value;
        b = value;
        a = value;
    }

    Color::Color(uint8_t r, uint8_t g, uint8_t b, uint8_t a) {
        this->r = r;
        this->g = g;
        this->b = b;
        this->a = a;
    }

    bool Color::operator ==(const Color &color) const {
        return r == color.r && g == color.g && b == color.b && a == color.a;
    }

    bool Color::operator !=(const Color &color) const {
        return r != color.r || g != color.g || b != color.b || a != color.a;
    }
}