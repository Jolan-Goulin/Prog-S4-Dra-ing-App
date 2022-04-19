#include "Load.h"
#include <stdexcept>
#include <string>
#define STBI_FAILURE_USERMSG // Asks stb to give us better error messages in stbi_failure_reason()
#include <stb_image/stb_image.h>

namespace img {

Image load(const char* file_path, int desired_channels_count, bool flip_vertically)
{
    stbi_set_flip_vertically_on_load(flip_vertically ? 1 : 0);
    int      w, h; // NOLINT
    uint8_t* data = stbi_load(file_path, &w, &h, nullptr, desired_channels_count);
    if (!data) {
        throw std::runtime_error{"[img::load] Couldn't load image from \"" + std::string{file_path} + "\":\n" + stbi_failure_reason()};
    }
    return Image{{static_cast<Size::DataType>(w),
                  static_cast<Size::DataType>(h)},
                 desired_channels_count,
                 data};
}

} // namespace img