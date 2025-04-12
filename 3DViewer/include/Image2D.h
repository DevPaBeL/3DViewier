#pragma once

#include <OpenGL/gl3.h>
#include <string>
#include <memory>
#include <glm/glm.hpp>

class Image2D {
public:
 Image2D(const std::string& path);
 ~Image2D();

   void bind(GLuint textureUnit = 0) const;
  int getWidth() const { return width; }
   int getHeight() const { return height; }
  GLuint getTextureId() const { return textureId; }
   void draw(const glm::mat4& view, const glm::mat4& projection);


    // Методы для управления положением
  void setPosition(const glm::vec3& pos) { position = pos; }
   void move(const glm::vec3& offset) { position += offset; }
 const glm::vec3& getPosition() const { return position; }

private:
  GLuint textureId; 
  int width;
 int height;
  int channels;
  GLuint VAO, VBO, EBO;
  glm::vec3 position{0.0f};
  void setupBuffers();
}; 