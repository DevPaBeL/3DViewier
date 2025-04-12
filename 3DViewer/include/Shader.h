#pragma once

#ifndef GL_SILENCE_DEPRECATION
#define GL_SILENCE_DEPRECATION
#endif

#include <string>
#include <glm/glm.hpp>

#include <OpenGL/gl3.h>

//Класс для работы с шейдерами OpenGL
class Shader {
public:

    Shader(const std::string& vertexPath, const std::string& fragmentPath);
    ~Shader();
  void use() const;
   void setBool(const std::string& name, bool value) const;  
  void setInt(const std::string& name, int value) const;

   void setFloat(const std::string& name, float value) const;

  void setVec3(const std::string& name, const glm::vec3& value) const; 
  void setMat4(const std::string& name, const glm::mat4& value) const;

private:
  void checkCompileErrors(GLuint shader, const std::string& type);
    GLuint ID;
}; 