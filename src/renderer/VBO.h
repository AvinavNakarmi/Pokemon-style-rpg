#pragma once
#include <glad/glad.h>
class VBO
{
private:
    GLuint ID;

public:
    VBO(GLfloat *vertices, GLsizeiptr size);
    VBO();
    ~VBO();
    void AttachData(GLfloat *vertices, GLsizeiptr size);
    GLuint GetID() const { return ID; }
};
