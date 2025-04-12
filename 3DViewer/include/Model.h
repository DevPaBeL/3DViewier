#pragma once

#ifndef GL_SILENCE_DEPRECATION
#define GL_SILENCE_DEPRECATION
#endif

#include <OpenGL/gl3.h>
#include <string>
#include <vector>
#include <glm/glm.hpp>
#include <assimp/scene.h>

//Класс для работы с 3D моделями

class Model {
public:

 Model(const std::string& path);
 ~Model();

  void draw() const;
    
  void setPosition(const glm::vec3& position);

   void setRotation(const glm::vec3& rotation);

 void setScale(const glm::vec3& scale);
    
  void update(float deltaTime);
 glm::mat4 getModelMatrix() const;
    
  bool isSelected() const { return selected; }

  void setSelected(bool value) { selected = value; }
   glm::vec3 position;
  glm::vec3 rotation;
  glm::vec3 scale;

private:

struct Mesh {
      GLuint VAO, VBO, EBO;
     std::vector<glm::vec3> vertices;
     std::vector<GLuint> indices;
};

  void loadModel(const std::string& path);
    
  void processNode(aiNode* node, const aiScene* scene);
  Mesh processMesh(aiMesh* mesh, const aiScene* scene);

  std::vector<Mesh> meshes;
 bool selected;
}; 