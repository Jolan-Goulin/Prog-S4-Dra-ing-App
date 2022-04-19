cmake_minimum_required(VERSION 3.8)

add_library(img)
add_library(img::img ALIAS img)
target_compile_features(img PRIVATE cxx_std_17)

if (img_ENABLE_WARNINGS_AS_ERRORS)
    message("-- [img] Enabling warnings as errors for img")
    if(MSVC)
        target_compile_options(img PRIVATE /WX /W4)
    else()
        target_compile_options(img PRIVATE -Werror -Wall -Wextra -Wpedantic -pedantic-errors -Wconversion -Wsign-conversion)
    endif()
else()
    message("-- [img] Not using warnings as errors for img")
endif()

# ---Add stb_image---
add_library(stb_image "lib/stb_image/stb_image.cpp"
                      "lib/stb_image/stb_image_write.cpp")
target_link_libraries(img PRIVATE stb_image)

# ---Add source files---
target_include_directories(img INTERFACE include)
target_include_directories(img PRIVATE lib)
target_sources(img PRIVATE
    src/Save.cpp
    src/Load.cpp
)