#pragma once
#include <glad/glad.h>
class EBO
{
private:
    GLuint ID;

public:
    EBO(GLuint *indices, GLsizeiptr size);
    EBO();
    ~EBO();
    GLuint GetID();
    void AttachData(GLuint *indices, GLsizeiptr size);
};
