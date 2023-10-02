#include <cstdint>

#include "size.h"

namespace sweet {
    template<typename T>
    Size<T>::Size() {
        width = 0;
        height = 0;
    }

    template<typename T>
    Size<T>::Size(T value) {
        width = value;
        height = value;
    }

    template<typename T>
    Size<T>::Size(T width, T height) {
        this->width = width;
        this->height = height;
    }

    template<typename T>
    bool Size<T>::operator ==(const Size<T> &size) const {
        return width == size.width && height == size.height;
    }

    template<typename T>
    bool Size<T>::operator !=(const Size<T> &size) const {
        return width != size.width || height != size.height;
    }

    template class Size<float>;
    template class Size<double>;
    template class Size<int8_t>;
    template class Size<int16_t>;
    template class Size<int32_t>;
    template class Size<int64_t>;
    template class Size<uint8_t>;
    template class Size<uint16_t>;
    template class Size<uint32_t>;
    template class Size<uint64_t>;
}