#pragma once
#include <glad/glad.h>
class VAO
{
public:
    VAO();
    ~VAO();
    void Bind() const;
    void AttachEBO(GLuint eboID);
    void AddVertexBuffer(GLuint vbo, GLuint bindingIndex, GLint size, GLenum type, GLsizei stride, GLuint attribIndex, GLuint offset);

    GLuint GetID();

private:
    GLuint ID;
};
