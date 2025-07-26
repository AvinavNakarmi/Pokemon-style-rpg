#include "renderer.h"

Renderer::Renderer()
{
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    GLfloat vertices[] = {
        -1.0f, -1.0f, 0.0f, // Bottom Left
        1.0f, -1.0f, 0.0f,  // Bottom Right
        1.0f, 1.0f, 0.0f,   // Top Right
        -1.0f, 1.0f, 0.0f,  // Top Left
    };
    GLfloat vertices2[] = {
        -1.0f, -1.0f, -1.0f, // Bottom Left
        1.0f, -1.0f, -1.0f,  // Bottom Right
        1.0f, 1.0f, -1.0f,   // Top Right
        -1.0f, 1.0f, -1.0f,  // Top Left
    };
    GLfloat texCoords[] = {
        0.0f, 1.0f, // Bottom Left
        1.0f, 1.0f, // Bottom Right
        1.0f, 0.0f, // Top Right
        0.0f, 0.0f  // Top Left
    };

    GLuint indices[] = {
        0, 1, 2, // First triangle
        2, 3, 0  // Second triangle

    };
    MeshData meshData(vertices2, sizeof(vertices2), indices, sizeof(indices), texCoords, sizeof(texCoords), "../src/shader/default1.vert", "../src/shader/default1.frag");
    mesh = new Mesh(meshData);
    mesh->setScale(glm::vec3(1.0));
    mesh->AddTexture("../src/assets/tilemap_packed.png");

    mesh2 = new Mesh(meshData);
    mesh2->AddTexture("../src/assets/pokesprite-pokemon-gen8.png");
    mesh2->setScale(glm::vec3(0.1));
}

void Renderer::Draw()
{
    float currentTime = glfwGetTime();

    if (currentTime - latestInput > 0.1f)
    {

        if (glfwGetKey(WindowHandler::getWindow(), GLFW_KEY_W) == GLFW_PRESS)
        {
            mesh2->translate(glm::vec3(0.0f, 0.1f, 0.0f));
        }
        if (glfwGetKey(WindowHandler::getWindow(), GLFW_KEY_A) == GLFW_PRESS)
        {
            mesh2->translate(glm::vec3(-0.1f, 0.0f, 0.0f));
        }
        if (glfwGetKey(WindowHandler::getWindow(), GLFW_KEY_D) == GLFW_PRESS)
        {
            mesh2->translate(glm::vec3(0.1f, 0.0f, 0.0f));
        }
        if (glfwGetKey(WindowHandler::getWindow(), GLFW_KEY_S) == GLFW_PRESS)
        {
            mesh2->translate(glm::vec3(0.0f, -0.1f, 0.0f));
        }
        latestInput = currentTime;
    }

    glEnable(GL_DEPTH_TEST);

    glClearColor(1.0f, 0.1f, 0.1f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    // mesh->Draw();
    glDepthMask(GL_FALSE);
    mesh->Draw();

    mesh2->Draw();
    glDepthMask(GL_TRUE);
}
Renderer::~Renderer()
{
    delete mesh2;
    delete mesh;

    glDeleteVertexArrays(1, &vao);
    glDeleteBuffers(1, &vbo);
    glDeleteProgram(shaderProgram);
}