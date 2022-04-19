#pragma once

#include <glpp/glpp.hpp>
#include "ImageSize.h"
#include "Texture2D.h"

namespace glpp {

class RenderTarget {
public:
    /// You can optionally upload some image data
    explicit RenderTarget(ImageSize     size,
                          const void*   data           = nullptr,
                          TextureLayout texture_layout = {});

    const Texture2D&         texture() const { return _texture; }
    const UniqueFramebuffer& framebuffer() const { return _framebuffer; }

    /// Binds this render target so that it will be the one that the following draw calls will render to
    /// It also calls glViewport to set the viewport to the size of this RenderTarget
    void bind() const;
    /// Resizes the render target
    /// /!\ All of its content is lost. If you don't want that you can use conservative_resize() instead
    void resize(ImageSize size);
    /// Resizes the render target and preserves its content
    void      conservative_resize(ImageSize size);
    ImageSize size() const;
    GLsizei   width() const { return size().width(); }
    GLsizei   height() const { return size().height(); }
    /// /!\ Changes the bound RenderTarget to be destination
    void blit_to(const RenderTarget& destination, Interpolation interpolation);
    /// /!\ Changes the bound RenderTarget to be dst_framebuffer_id
    void blit_to(GLuint dst_framebuffer_id, ImageSize dst_framebuffer_size, Interpolation interpolation);

    static GLuint screen_framebuffer_id() { return 0; }

    TextureLayout texture_layout() const { return _texture_layout; }

private:
    UniqueFramebuffer _framebuffer;
    Texture2D         _texture;
    TextureLayout     _texture_layout;
};

} // namespace glpp