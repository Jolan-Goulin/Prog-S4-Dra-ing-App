#pragma once

#include "Size.h"

namespace img {
namespace SizeU {

/// Returns the aspect ratio of the rectangle, aka width / height
template<typename T>
float aspect_ratio(SizeT<T> size)
{
    return static_cast<float>(size.width()) / static_cast<float>(size.height());
}

/// Returns the biggest SizeT<float> that fits into frame and has the same aspect ratio as image
template<typename T>
SizeT<float> fit_into(SizeT<T> frame, SizeT<T> image)
{
    auto image_aspect = aspect_ratio(image);
    auto frame_aspect = aspect_ratio(frame);
    if (image_aspect < frame_aspect) {
        return {
            static_cast<float>(frame.height()) * image_aspect,
            static_cast<float>(frame.height())};
    }
    else {
        return {
            static_cast<float>(frame.width()),
            static_cast<float>(frame.width()) / image_aspect};
    }
}

} // namespace SizeU
} // namespace img