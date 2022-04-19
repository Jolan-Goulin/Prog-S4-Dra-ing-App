#pragma once

#include <glpp/glpp.hpp>
#include "ImageSize.h"
#include "TextureLayout.h"
#include "internal/TextureBase.h"

namespace glpp {

namespace internal {

inline void upload_data_impl(GLuint id, ImageSize size, const void* data, TextureLayout layout)
{
    texture_image_2D(id, layout.internal_format, size.width(), size.height(), layout.channels, layout.texel_data_type, data);
}

} // namespace internal

class Texture2D : public internal::TextureBase<UniqueTexture2D, ImageSize, &internal::upload_data_impl> {
public:
    explicit Texture2D(Interpolation minification_filter  = Interpolation::NearestNeighbour,
                       Interpolation magnification_filter = Interpolation::Linear,
                       Wrap          horizontal_wrap      = Wrap::Repeat,
                       Wrap          vertical_wrap        = Wrap::Repeat)
        : internal::TextureBase<UniqueTexture2D, ImageSize, &internal::upload_data_impl>{minification_filter, magnification_filter}
    {
        set_wrap_s(_id, horizontal_wrap);
        set_wrap_t(_id, vertical_wrap);
    }
};

} // namespace glpp