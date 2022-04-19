#pragma once

#include <glpp/glpp.hpp>
#include "TextureLayout.h"
#include "internal/TextureBase.h"

namespace glpp {

struct Texture3DSize {
    GLsizei width{};
    GLsizei height{};
    GLsizei depth{};
};

namespace internal {

inline void upload_data_impl(GLuint id, Texture3DSize size, const void* data, TextureLayout layout)
{
    texture_image_3D(id, layout.internal_format, size.width, size.height, size.depth, layout.channels, layout.texel_data_type, data);
}

} // namespace internal

class Texture3D : public internal::TextureBase<UniqueTexture3D, Texture3DSize, &internal::upload_data_impl> {
public:
    explicit Texture3D(Interpolation minification_filter  = Interpolation::NearestNeighbour,
                       Interpolation magnification_filter = Interpolation::Linear,
                       Wrap          wrap_width           = Wrap::Repeat,
                       Wrap          wrap_height          = Wrap::Repeat,
                       Wrap          wrap_depth           = Wrap::Repeat)
        : internal::TextureBase<UniqueTexture3D, Texture3DSize, &internal::upload_data_impl>{minification_filter, magnification_filter}
    {
        set_wrap_s(_id, wrap_width);
        set_wrap_t(_id, wrap_height);
        set_wrap_r(_id, wrap_depth);
    }
};

} // namespace glpp