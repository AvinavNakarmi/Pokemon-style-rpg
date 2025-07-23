#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <vector>
#include "VBO.h"
#include "../object/mesh.h"
class Renderer
{
public:
    Renderer();
    ~Renderer();
    void Draw();

private:
    GLuint shaderProgram;
    Mesh *mesh;
    Mesh *mesh2;

    // GLuint createProgram(const char *vertSrc, const char *fragSrc);

    // GLuint compileShader(GLenum type, const char *source);
    GLuint vao, vbo;
};
