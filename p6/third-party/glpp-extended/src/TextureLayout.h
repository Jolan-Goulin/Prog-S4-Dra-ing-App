#pragma once

#include <glpp/glpp.hpp>

namespace glpp {

struct TextureLayout {
    InternalFormat internal_format = InternalFormat::RGBA;
    Channels       channels        = Channels::RGBA;
    TexelDataType  texel_data_type = TexelDataType::UnsignedByte;
};

} // namespace glpp