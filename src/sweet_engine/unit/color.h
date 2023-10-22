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

    // 参考 https://www.color-site.com/color_basics
    #define SW_COLOR_WHITE sweet::Color{255, 255, 255}
    #define SW_COLOR_SILVER sweet::Color{192, 192, 192}
    #define SW_COLOR_GRAY sweet::Color{128, 128, 128}
    #define SW_COLOR_BLACK sweet::Color{0, 0, 0}
    #define SW_COLOR_RED sweet::Color{255, 0, 0}
    #define SW_COLOR_MAROON sweet::Color{128, 0, 0}
    #define SW_COLOR_YELLOW sweet::Color{255, 255, 0}
    #define SW_COLOR_OLIVE sweet::Color{128, 128, 0}
    #define SW_COLOR_LIME sweet::Color{0, 255, 0}
    #define SW_COLOR_GREEN sweet::Color{0, 128, 0}
    #define SW_COLOR_AQUA sweet::Color{0, 255, 255}
    #define SW_COLOR_TEAL sweet::Color{0, 128, 128}
    #define SW_COLOR_BLUE sweet::Color{0, 0, 255}
    #define SW_COLOR_NAVY sweet::Color{0, 0, 128}
    #define SW_COLOR_FUCHSIA sweet::Color{255, 0, 255}
    #define SW_COLOR_PURPLE sweet::Color{128, 0, 128}
}

#endif // ENGINE_UNIT_COLOR_H_