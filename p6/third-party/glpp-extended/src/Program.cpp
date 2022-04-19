#include "Program.h"
#include <algorithm>
#include <glm/gtc/type_ptr.hpp>

namespace glpp {
namespace ext {

GLint Program::uniform_location(const std::string& uniform_name) const
{
    const auto it = std::find_if(_uniform_locations.begin(), _uniform_locations.end(), [&](auto&& pair) {
        return pair.first == uniform_name;
    });
    if (it != _uniform_locations.end()) {
        return it->second;
    }
    else {
        const auto location = _program.compute_uniform_location(uniform_name.c_str());
        _uniform_locations.emplace_back(uniform_name, location);
        return location;
    }
}

void Program::set(const std::string& uniform_name, int v) const
{
    _program.set_uniform(uniform_location(uniform_name), v);
}
void Program::set(const std::string& uniform_name, unsigned int v) const
{
    set(uniform_name, static_cast<int>(v));
}
void Program::set(const std::string& uniform_name, bool v) const
{
    set(uniform_name, v ? 1 : 0);
}
void Program::set(const std::string& uniform_name, float v) const
{
    _program.set_uniform(uniform_location(uniform_name), v);
}
void Program::set(const std::string& uniform_name, const glm::vec2& v) const
{
    _program.set_uniform(uniform_location(uniform_name), v.x, v.y);
}
void Program::set(const std::string& uniform_name, const glm::vec3& v) const
{
    _program.set_uniform(uniform_location(uniform_name), v.x, v.y, v.z);
}
void Program::set(const std::string& uniform_name, const glm::vec4& v) const
{
    _program.set_uniform(uniform_location(uniform_name), v.x, v.y, v.z, v.w);
}
void Program::set(const std::string& uniform_name, const glm::mat2& mat) const
{
    _program.set_uniform_mat2(uniform_location(uniform_name), glm::value_ptr(mat));
}
void Program::set(const std::string& uniform_name, const glm::mat3& mat) const
{
    _program.set_uniform_mat3(uniform_location(uniform_name), glm::value_ptr(mat));
}
void Program::set(const std::string& uniform_name, const glm::mat4& mat) const
{
    _program.set_uniform_mat4(uniform_location(uniform_name), glm::value_ptr(mat));
}

} // namespace ext
} // namespace glpp