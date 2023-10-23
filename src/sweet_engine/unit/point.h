#ifndef ENGINE_UNIT_POINT_H_
#define ENGINE_UNIT_POINT_H_

namespace sweet {
    template <typename T>
    struct Point {
        T x;
        T y;

        Point();
        Point(T value);
        Point(T x, T y);

        bool operator ==(const Point<T> &point) const;
        bool operator !=(const Point<T> &point) const;
    };
}

#endif // ENGINE_UNIT_POINT_H_
