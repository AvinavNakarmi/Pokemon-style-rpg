#include "renderer.h"

Renderer::Renderer()
{
    GLfloat texCoords[] = {
        0.0f, 0.0f,
        1.0f, 0.0f,
        0.5f, 1.0f};
    GLfloat vertices[] = {
        -0.5f,
        -0.5f,
        0.0f,
        0.5f,
        -0.5f,
        0.0f,
        0.0f,
        0.5f,
        0.0f};
    GLfloat vertices2[] = {
        -0.1f,
        -0.2f,
        -1.0f,
        0.5f,
        -0.5f,
        -1.0f,
        0.0f,
        0.1f,
        -1.0f};

    GLuint indices[] = {0, 1, 2};

    mesh = new Mesh(
        // Vertex data
        vertices,
        sizeof(vertices),
        // Index data
        indices,
        sizeof(indices), "../src/shader/default.vert",
        "../src/shader/default.frag");

    mesh2 = new Mesh(
        // Vertex data
        vertices2,
        sizeof(vertices2),
        // Index data
        indices,
        sizeof(indices), "../src/shader/default1.vert",
        "../src/shader/default1.frag");
    mesh2->AddTexture("../src/assets/tilemap.png");
}

void Renderer::Draw()
{
    glEnable(GL_DEPTH_TEST);

    glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    mesh->Draw();
    mesh2->Draw();
}
Renderer::~Renderer()
{
    delete mesh;
    delete mesh2;

    glDeleteVertexArrays(1, &vao);
    glDeleteBuffers(1, &vbo);
    glDeleteProgram(shaderProgram);
}