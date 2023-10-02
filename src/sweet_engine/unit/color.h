#ifndef ENGINE_UNIT_COLOR_H_
#define ENGINE_UNIT_COLOR_H_

#include <cstdint>

namespace sweet {
    struct Color {
        uint8_t r;
        uint8_t g;
        uint8_t b;
        uint8_t a;

        Color();
        Color(uint8_t value);
        Color(uint8_t r, uint8_t g, uint8_t b, uint8_t a = 255);

        bool operator ==(const Color &color) const;
        bool operator !=(const Color &color) const;
    };
}

#endif // ENGINE_UNIT_COLOR_H_