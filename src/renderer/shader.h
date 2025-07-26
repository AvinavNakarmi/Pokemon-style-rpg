#pragma once
#include <glad/glad.h>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <cerrno>
std::string get_file_contents(const char *filename);
class Shader
{
public:
    // GLuint createShader(const char *shaderSource, GLenum type);

    Shader(const char *vertexFile, const char *fragmentFile);
    void Use();
    void Activate();

    ~Shader();
    GLuint createShader(const char *shaderSource, GLenum type);

    GLuint GetID() const { return ID; }

private:
    GLuint ID; // Shader program ID
};
