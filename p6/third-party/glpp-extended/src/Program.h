#pragma once

#include <glm/glm.hpp>
#include <glpp/glpp.hpp>
#include <string>
#include <utility>
#include <vector>

namespace glpp {
namespace ext {

/// + Automatic uniform location handling: the first time a uniform is encountered its location is looked up, and then it is stored in a cache for next time
/// + set() recognizes glm types and sets the uniform accordingly
class Program {
public:
    void       attach_shader(GLuint shader_id) const { _program.attach_shader(shader_id); }
    void       link() const { _program.link(); }
    MaybeError check_linking_errors() const { return _program.check_linking_errors(); }

    GLuint operator*() const { return *_program; }
    void   use() const { _program.use(); }
    void   set(const std::string& uniform_name, int v) const;
    void   set(const std::string& uniform_name, unsigned int v) const;
    void   set(const std::string& uniform_name, bool v) const;
    void   set(const std::string& uniform_name, float v) const;
    void   set(const std::string& uniform_name, const glm::vec2& v) const;
    void   set(const std::string& uniform_name, const glm::vec3& v) const;
    void   set(const std::string& uniform_name, const glm::vec4& v) const;
    void   set(const std::string& uniform_name, const glm::mat2& mat) const;
    void   set(const std::string& uniform_name, const glm::mat3& mat) const;
    void   set(const std::string& uniform_name, const glm::mat4& mat) const;

private:
    GLint uniform_location(const std::string& uniform_name) const;

private:
    glpp::Program                                      _program;
    mutable std::vector<std::pair<std::string, GLint>> _uniform_locations;
};

} // namespace ext
} // namespace glpp
