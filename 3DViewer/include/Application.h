#pragma once

#ifndef GL_SILENCE_DEPRECATION
#define GL_SILENCE_DEPRECATION
#endif


#include <OpenGL/gl3.h>
#include <GLFW/glfw3.h>
#include <vector>
#include <memory>
#include "Model.h"
#include "Shader.h"
#include <glm/glm.hpp>
#include "Image2D.h"

//Основной класс управляющий всем процессом взаимодействия с приложением
 
class Application {
public:
    Application();
    ~Application();
    void run();

private:
  void initGLFW();
  void initOpenGL();
void mainLoop();
  void cleanup();
   void processInput();
      void handleMouseInput();
  void handleKeyboardInput();
  void update(float deltaTime);
    void render();
 Model* pickModel(float mouseX, float mouseY);
  glm::vec3 screenToWorldRay(float mouseX, float mouseY);
 bool rayIntersectsModel(const glm::vec3& rayOrigin, const glm::vec3& rayDir, const Model* model);


    //функции для GLFW
 static void framebufferSizeCallback(GLFWwindow* window, int width, int height);
  static void mouseCallback(GLFWwindow* window, double xpos, double ypos);
  static void scrollCallback(GLFWwindow* window, double xoffset, double yoffset);
   static void mouseButtonCallback(GLFWwindow* window, int button, int action, int mods);
    static void dropCallback(GLFWwindow* window, int count, const char** paths);
   void handleDroppedFiles(int count, const char** paths);
  bool isImageFile(const std::string& path);

    // Члены класса
  GLFWwindow* window;
   int windowWidth;
  int windowHeight;
   float lastFrameTime;
  float deltaTime;

 std::unique_ptr<Shader> shader;
   std::vector<std::unique_ptr<Model>> models;
     std::vector<std::unique_ptr<Image2D>> images;
     Model* selectedModel;
     bool isDragging;
     bool deleteKeyPressed;
     glm::vec2 lastMousePos;
     glm::vec3 cameraPos;
     glm::vec3 cameraFront;
     glm::vec3 cameraUp;
     float yaw;
     float pitch;
     float fov;
}; 