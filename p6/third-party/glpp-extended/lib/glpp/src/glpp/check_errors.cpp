#include "check_errors.h"
#include <glad/glad.h>
#include <iostream>
#include <sstream>

namespace glpp {

static bool context_is_active = true;

static std::function<void(std::string&&)>& error_callback()
{
    static std::function<void(std::string &&)> cb = [](std::string&& error_message) {
        std::cerr << error_message << '\n';
    };
    return cb;
}

void set_error_callback(std::function<void(std::string&&)> callback)
{
    error_callback() = callback;
}

void shut_down()
{
    context_is_active = false;
}

namespace internal {

#if GLPP_SHOULD_CHECK_ERRORS
static const char* gl_error_to_string(GLenum err)
{
    switch (err) {
    case GL_NO_ERROR:
        return "GL_NO_ERROR";

    case GL_INVALID_ENUM:
        return "GL_INVALID_ENUM";

    case GL_INVALID_VALUE:
        return "GL_INVALID_VALUE";

    case GL_INVALID_OPERATION:
        return "GL_INVALID_OPERATION";

    case GL_INVALID_FRAMEBUFFER_OPERATION:
        return "GL_INVALID_FRAMEBUFFER_OPERATION";

    case GL_OUT_OF_MEMORY:
        return "GL_OUT_OF_MEMORY";

    case GL_STACK_UNDERFLOW:
        return "GL_STACK_UNDERFLOW";

    case GL_STACK_OVERFLOW:
        return "GL_STACK_OVERFLOW";

    default:
        return "UNKNOWN_ERROR_TYPE";
    }
}

void check_errors_with_info(const char* file_name, const char* function_name, int line)
{
    if (context_is_active) {
        std::stringstream error_message;
        bool              has_found_errors = false;
        GLenum            error;                        // NOLINT
        while ((error = glGetError()) != GL_NO_ERROR) { // NB: if you freeze here during shutdown it means that you forgot to call glpp::shut_down()
            error_message << "[OpenGL Error] " << gl_error_to_string(error)
                          << " in " << function_name << "(), " << file_name << '(' << line << ")\n";
            has_found_errors = true;
        }
        if (has_found_errors) {
            error_callback()(error_message.str());
        }
    }
}
#endif

} // namespace internal

} // namespace glpp