#ifndef ENGINE_UNIT_SIZE_H_
#define ENGINE_UNIT_SIZE_H_

namespace sweet {
    template<typename T>
    struct Size {
        T width;
        T height;

        Size();
        Size(T value);
        Size(T width, T height);

        bool operator ==(const Size<T> &size) const;
        bool operator !=(const Size<T> &size) const;
    };
}

#endif // ENGINE_UNIT_SIZE_H_