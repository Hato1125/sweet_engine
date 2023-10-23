#ifndef ENGINE_UNIT_RECTANGLE_H_
#define ENGINE_UNIT_RECTANGLE_H_

namespace sweet {
    template <typename T>
    struct Rectangle {
        T x;
        T y;
        T width;
        T height;

        Rectangle();
        Rectangle(T value);
        Rectangle(T x, T y, T width, T height);

        bool operator ==(const Rectangle<T> &rect) const;
        bool operator !=(const Rectangle<T> &rect) const;
    };
}

#endif // ENGINE_UNIT_RECTANGLE_H_