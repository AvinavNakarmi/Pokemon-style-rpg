
#include "VAO.h"

VAO::VAO()
{
    glCreateVertexArrays(1, &ID);
}
VAO::~VAO()
{
    glDeleteVertexArrays(1, &ID);
}

void VAO::AddVertexBuffer(GLuint vbo, GLuint bindingIndex, int size, GLenum type, GLsizei stride, GLuint attribIndex, GLuint offset)
{
    glVertexArrayVertexBuffer(ID, bindingIndex, vbo, 0, stride);
    glEnableVertexArrayAttrib(ID, attribIndex);
    glVertexArrayAttribFormat(ID, attribIndex, size, type, GL_FALSE, offset);
    glVertexArrayAttribBinding(ID, attribIndex, bindingIndex);
}
void VAO::Bind() const
{
    glBindVertexArray(ID);
}
GLuint VAO::GetID()
{
    return ID;
}
void VAO::AttachEBO(GLuint eboID)
{
    glVertexArrayElementBuffer(ID, eboID);
}