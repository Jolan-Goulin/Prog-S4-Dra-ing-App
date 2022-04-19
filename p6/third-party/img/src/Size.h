#pragma once

#include <cassert>
#include <cstdint>

namespace img {

/// Represents the width and height of an axis-aligned rectangle.
/// width and height are guaranteed to be >= 1
/// The template parameter T is the type of width and height
template<typename T>
class SizeT {
public:
    /// The type of width and height
    using DataType = T;

    SizeT() = default;
    SizeT(DataType w, DataType h)
        : _width{w}, _height{h}
    {
        assert(w >= 1 && h >= 1);
    }
    friend bool operator==(const SizeT& lhs, const SizeT& rhs) { return lhs.width() == rhs.width() && lhs.height() == rhs.height(); }
    friend bool operator!=(const SizeT& lhs, const SizeT& rhs) { return !(lhs == rhs); }
    template<typename U>
    explicit operator SizeT<U>() const
    {
        return SizeT<U>{static_cast<U>(_width), static_cast<U>(_height)};
    }

    DataType width() const { return _width; }
    DataType height() const { return _height; }

    /// Sets the width; it must be >= 1
    void set_width(DataType w)
    {
        assert(w >= 1);
        _width = w;
    }

    /// Sets the height; it must be >= 1
    void set_height(DataType h)
    {
        assert(h >= 1);
        _height = h;
    }

private:
    DataType _width  = 1;
    DataType _height = 1;
};

using Size = SizeT<uint32_t>;

} // namespace img