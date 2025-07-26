#pragma once
#include <glad/glad.h>

struct MeshData
{
    GLfloat *vertices;
    size_t vertex_size;
    GLuint *indices;
    size_t indices_size;
    GLfloat *textureCoords;
    size_t textureCoords_size;
    const char *vertexFile;
    const char *fragmentFile;

    MeshData(GLfloat *v, size_t vs, GLuint *i, size_t is, GLfloat *tc, size_t tcs, const char *vf, const char *ff)
        : vertices(v), vertex_size(vs), indices(i), indices_size(is), textureCoords(tc), textureCoords_size(tcs), vertexFile(vf), fragmentFile(ff) {}
};