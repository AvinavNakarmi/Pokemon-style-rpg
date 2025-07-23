#include "EBO.h"

EBO::EBO(GLuint *indices, GLsizeiptr size)
{
    glCreateBuffers(1, &ID);
    glNamedBufferData(ID, size, indices, GL_STATIC_DRAW);
}
EBO ::EBO()
{
    glCreateBuffers(1, &ID);
}
void EBO::AttachData(GLuint *indices, GLsizeiptr size)
{
    glNamedBufferData(ID, size, indices, GL_STATIC_DRAW);
}

EBO::~EBO()
{
    glDeleteBuffers(1, &ID);
}
GLuint EBO::GetID()
{
    return ID;
}