#include <cstdint>

#include "rectangle.h"

namespace sweet {
    template <typename T>
    Rectangle<T>::Rectangle() {
        x = 0;
        y = 0;
        width = 0;
        height = 0;
    }

    template <typename T>
    Rectangle<T>::Rectangle(T value) {
        x = value;
        y = value;
        width = value;
        height = value;
    }

    template <typename T>
    Rectangle<T>::Rectangle(T x, T y, T width, T height) {
        this->x = x;
        this->y = y;
        this->width = width;
        this->height = height;
    }

    template <typename T>
    bool Rectangle<T>::operator ==(const Rectangle<T> &rect) const {
        return x == rect.x && y == rect.y
            && width == rect.width && height == rect.height;
    }

    template <typename T>
    bool Rectangle<T>::operator !=(const Rectangle<T> &rect) const {
        return x != rect.x || y != rect.y
            || width != rect.width || height != rect.height;
    }

    template struct Rectangle<float>;
    template struct Rectangle<double>;
    template struct Rectangle<int8_t>;
    template struct Rectangle<int16_t>;
    template struct Rectangle<int32_t>;
    template struct Rectangle<int64_t>;
    template struct Rectangle<uint8_t>;
    template struct Rectangle<uint16_t>;
    template struct Rectangle<uint32_t>;
    template struct Rectangle<uint64_t>;
}