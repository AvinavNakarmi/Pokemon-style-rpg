#include "VBO.h"

VBO::VBO(GLfloat *vertices, GLsizeiptr size)
{
    glCreateBuffers(1, &ID);
    glNamedBufferData(ID, size, vertices, GL_STATIC_DRAW);
}

VBO::VBO()
{

    glCreateBuffers(1, &ID);
}
void VBO::AttachData(GLfloat *vertices, GLsizeiptr size)
{
    glNamedBufferData(ID, size, vertices, GL_STATIC_DRAW);
}
VBO::~VBO()
{
    glDeleteBuffers(1, &ID);
}
