#include <cstdint>

#include "point.h"

namespace sweet {
    template<typename T>
    Point<T>::Point() {
        x = 0;
        y = 0;
    }

    template<typename T>
    Point<T>::Point(T value) {
        x = value;
        y = value;
    }

    template<typename T>
    Point<T>::Point(T x, T y) {
        this->x = x;
        this->y = y;
    }

    template<typename T>
    bool Point<T>::operator ==(const Point<T> &point) const {
        return x == point.x && y == point.y;
    }

    template<typename T>
    bool Point<T>::operator !=(const Point<T> &point) const {
        return x != point.x || y != point.y;
    }

    template class Point<float>;
    template class Point<double>;
    template class Point<int8_t>;
    template class Point<int16_t>;
    template class Point<int32_t>;
    template class Point<int64_t>;
    template class Point<uint8_t>;
    template class Point<uint16_t>;
    template class Point<uint32_t>;
    template class Point<uint64_t>;
}