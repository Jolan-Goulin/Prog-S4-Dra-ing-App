#pragma once

#include <glpp/glpp.hpp>
#include "TextureLayout.h"
#include "internal/TextureBase.h"

namespace glpp {

namespace internal {

inline void upload_data_impl(GLuint id, GLsizei size, const void* data, TextureLayout layout)
{
    texture_image_1D(id, layout.internal_format, size, layout.channels, layout.texel_data_type, data);
}

} // namespace internal

class Texture1D : public internal::TextureBase<UniqueTexture1D, GLsizei, &internal::upload_data_impl> {
public:
    explicit Texture1D(Interpolation minification_filter  = Interpolation::NearestNeighbour,
                       Interpolation magnification_filter = Interpolation::Linear,
                       Wrap          wrap                 = Wrap::Repeat)
        : internal::TextureBase<UniqueTexture1D, GLsizei, &internal::upload_data_impl>{minification_filter, magnification_filter}
    {
        set_wrap_s(_id, wrap);
    }
};

} // namespace glpp