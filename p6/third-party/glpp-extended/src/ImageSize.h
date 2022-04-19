#pragma once

#include <glad/glad.h>
#include <cassert>

namespace glpp {

/// Represents the width and height of an axis-aligned rectangle. width() and height() are guaranteed to be >= 1
class ImageSize {
public:
    ImageSize() = default;
    ImageSize(GLsizei w, GLsizei h)
        : _width{w}, _height{h}
    {
        assert(w >= 1 && h >= 1);
    }

    GLsizei width() const { return _width; }
    GLsizei height() const { return _height; }
    float   aspect_ratio() const { return static_cast<float>(_width) / static_cast<float>(_height); }
    float   inverse_aspect_ratio() const { return static_cast<float>(_height) / static_cast<float>(_width); }

    /// Sets the width. It must be >= 1
    void set_width(GLsizei w)
    {
        assert(w >= 1);
        _width = w;
    }

    /// Sets the height. It must be >= 1
    void set_height(GLsizei h)
    {
        assert(h >= 1);
        _height = h;
    }

private:
    GLsizei _width;
    GLsizei _height;
};

} // namespace glpp