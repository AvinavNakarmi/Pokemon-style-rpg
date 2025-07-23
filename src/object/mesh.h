#include <glad/glad.h>
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <cerrno>
#include "../renderer/VAO.h"
#include "../renderer/VBO.h"
#include "../renderer/EBO.h"
#include "../renderer/shader.h"
#include "../../libs/stb/stb_image.h"
class Mesh
{
public:
    Mesh(GLfloat *vertices, size_t vertex_size, GLuint *indices, size_t indices_size, const char *vertexFile, const char *fragmentFile);
    void Draw();
    ~Mesh();
    void AddTexture(const char *textureFile);

private:
    VAO vao;
    VBO vbo;
    EBO ebo;
    Shader *shader;
};