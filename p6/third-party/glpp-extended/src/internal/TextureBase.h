#pragma once

#include "../TextureLayout.h"

namespace glpp::internal {

template<typename UniqueTextureT, typename SizeType, void (*upload_data_impl)(GLuint, SizeType, const void*, TextureLayout)>
class TextureBase {
public:
    explicit TextureBase(Interpolation minification_filter  = Interpolation::NearestNeighbour,
                         Interpolation magnification_filter = Interpolation::Linear);

    void     bind() const;
    void     bind_to_texture_unit(GLenum slot_idx) const;
    SizeType size() const { return _size; }
    void     resize(SizeType size, TextureLayout layout = {});
    void     upload_data(SizeType size, const void* data, TextureLayout layout = {});
    GLuint   operator*() const { return *_id; }

protected:
    UniqueTextureT _id;

private:
    SizeType _size{};
};

} // namespace glpp::internal

#include "TextureBase.tpp"