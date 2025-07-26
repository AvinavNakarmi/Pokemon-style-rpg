#include <glad/glad.h>
#include <glfw/glfw3.h>
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <cerrno>
#include "../renderer/VAO.h"
#include "../renderer/VBO.h"
#include "../renderer/EBO.h"
#include "../renderer/shader.h"
#include "../handler/window_handler.h"
#include "../util/structs.h"
#include <unordered_map>
#include <any>
#include <string>
#include "../../libs/stb_img/stb_image.h"
#include <glm/vec3.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

struct Texture
{
    int width;
    int height;
    int channels;
    GLuint textureID;
};

class Mesh
{
public:
    Mesh(MeshData meshData);
    ~Mesh();
    void Draw();
    void AddTexture(const char *textureFile);
    GLuint getUniformLocation(const char *name);
    void setPostiton(glm::vec3 position);
    void setRotation(glm::vec3 rotation);
    void setScale(glm::vec3 scale);
    glm::vec3 getPostion();
    glm::vec3 getScale();
    glm::vec3 getRotation();
    void translate(glm::vec3 translation);
    void rotate(glm::vec3 translation);
    void scaling(glm::vec3 translation);
    void setUniformData(std::string uniformName, std::any uniformData);

private:
    glm::vec3 position;
    glm::vec3 rotation;
    glm::vec3 scale;
    std::unordered_map<std::string, std::any> uniform;
    void ApplyUniform();

    int drwawCalls = 0;
    VAO vao;
    VBO vbo;
    EBO ebo;
    Shader *shader;
    GLuint textureID;
    Texture texture;
};