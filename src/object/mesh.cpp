
#include "mesh.h"

Mesh::Mesh(GLfloat *vertices, size_t vertex_size, GLuint *indices, size_t indices_size, const char *vertexFile, const char *fragmentFile)
{

    std::cout << "Mesh created." << std::endl;
    vbo.AttachData(vertices, vertex_size);
    ebo.AttachData(indices, indices_size);
    vao.AddVertexBuffer(vbo.GetID(), 0, 3, GL_FLOAT, 3 * sizeof(GLuint), 0, 0);
    vao.AttachEBO(ebo.GetID());
    std::cout << vertexFile << std::endl;

    shader = new Shader(vertexFile, fragmentFile);
}
void Mesh::Draw()
{
    shader->Use();
    glBindVertexArray(vao.GetID());
    glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);
}

Mesh::~Mesh()
{
    delete shader;
    std::cout << "Mesh destroyed." << std::endl;
}

void Mesh ::AddTexture(const char *textureFile)
{
    int width, height, channels;
    unsigned char *data = stbi_load(textureFile, &width, &height, &channels, STBI_rgb_alpha);
    if (!data)
    {
        std::cerr << "Failed to load texture: " << textureFile << std::endl;
        return;
    }
    // Implementation for adding texture can be added here
    std::cout << "AddTexture called." << std::endl;
}