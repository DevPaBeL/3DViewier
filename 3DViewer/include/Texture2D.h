#pragma once

#include <string>
#include <GLFW/glfw3.h>

//Класс для работы с 2Д
class Texture2D {
public:
   Texture2D(const std::string& path);
  ~Texture2D();

 void bind() const;
   void unbind() const;
  unsigned int getID() const { return textureID; }
   int getWidth() const { return width; }
  int getHeight() const { return height; }

private:
  unsigned int textureID;
   int width;
 int height;
  int channels;
}; 