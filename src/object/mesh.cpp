
#include "mesh.h"

Mesh::Mesh(MeshData meshData)
{
    GLfloat texCoords[] = {

        0.0f, 1.0f,
        1.0f, 1.0f,
        1.0f, 0.0f,
        0.0f, 0.0f};
    position = glm::vec3(0.0f, 0.0f, 0.0f);
    rotation = glm::vec3(0.0f, 0.0f, 0.0f);
    scale = glm::vec3(1.0f, 1.0f, 1.0f);
    glm::mat4 modal = glm::mat4(1.0f);

    this->setUniformData("modal", modal);
    std::cout
        << "Mesh created." << std::endl;
    vbo.AttachData(meshData.vertices, meshData.vertex_size);
    vao.AddVertexBuffer(vbo.GetID(), 0, 3, GL_FLOAT, 3 * sizeof(GLfloat), 0, 0);

    GLuint texCoordVBO;
    glCreateBuffers(1, &texCoordVBO);
    glNamedBufferData(texCoordVBO, meshData.textureCoords_size, meshData.textureCoords, GL_STATIC_DRAW);
    vao.AddVertexBuffer(texCoordVBO, 1, 2, GL_FLOAT, 2 * sizeof(GLfloat), 1, 0);

    ebo.AttachData(meshData.indices, meshData.indices_size);
    vao.AttachEBO(ebo.GetID());

    shader = new Shader(meshData.vertexFile, meshData.fragmentFile);
}
void Mesh::Draw()
{
    shader->Use();
    glBindVertexArray(vao.GetID());
    glBindTextureUnit(0, textureID);
    glUniform1i(glGetUniformLocation(shader->GetID(), "u_Texture"), 0);
    GLuint atlasSizeLocation = this->getUniformLocation("u_AtlasSize");
    GLint size[2] = {12, 11};
    glUniform2iv(atlasSizeLocation, 1, size);
    GLuint tileIndexLocation = this->getUniformLocation("u_TileIndex");
    GLint size2[2] = {5, 5};
    glUniform2iv(tileIndexLocation, 1, size2);
    GLuint timeLocation = this->getUniformLocation("u_time");
    glUniform1i(timeLocation, (drwawCalls / 50) % 12);

        glm::mat4 modal = glm::mat4(1.0f);
    glm::mat4 view = glm::mat4(1.0f);
    glm::mat4 projection = glm::mat4(1.0f);
    view = glm::translate(view, glm::vec3(0.0f, 0.0f, -1.0f));
    projection = glm::perspective(glm::radians(45.0f), (float)(800 / 800), 0.1f, 100.0f);
    modal = glm::translate(modal, position);
    modal = glm::rotate(modal, glm::radians(rotation.x), glm::vec3(1, 0, 0));
    modal = glm::rotate(modal, glm::radians(rotation.y), glm::vec3(0, 1, 0));
    modal = glm::rotate(modal, glm::radians(rotation.z), glm::vec3(0, 0, 1));
    modal = glm::scale(modal, scale);

    glUniformMatrix4fv(glGetUniformLocation(shader->GetID(), "uModel"), 1, GL_FALSE, glm::value_ptr(modal));

    glUniformMatrix4fv(glGetUniformLocation(shader->GetID(), "uView"), 1, GL_FALSE, glm::value_ptr(view));

    glUniformMatrix4fv(glGetUniformLocation(shader->GetID(), "uProjection"), 1, GL_FALSE, glm::value_ptr(projection));

    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);
    drwawCalls++;
}

Mesh::~Mesh()
{
    delete shader;
    std::cout << "Mesh destroyed." << std::endl;
}

void Mesh ::AddTexture(const char *textureFile)
{
    std ::cout << "AddTexture called." << std::endl;
    unsigned char *data = stbi_load(textureFile, &texture.width, &texture.height, &texture.channels, STBI_rgb_alpha);
    if (!data)
    {
        std::cerr << "Failed to load texture: " << textureFile << std::endl;
        return;
    }
    glCreateTextures(GL_TEXTURE_2D, 1, &textureID);
    glTextureStorage2D(textureID, 1, GL_RGBA8, texture.width, texture.height);
    glTextureSubImage2D(textureID, 0, 0, 0, texture.width, texture.height, GL_RGBA, GL_UNSIGNED_BYTE, data);

    // Set texture parameters
    glTextureParameteri(textureID, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_LINEAR);
    glTextureParameteri(textureID, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTextureParameteri(textureID, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTextureParameteri(textureID, GL_TEXTURE_WRAP_T, GL_REPEAT);

    // pass texture  width and height to shader

    stbi_image_free(data);

    // Implementation for adding texture can be added here
    std::cout << "AddTexture called." << std::endl;
}
GLuint Mesh::getUniformLocation(const char *name)
{
    return glGetUniformLocation(shader->GetID(), name);
}

glm::vec3 Mesh::getPostion()
{
    return position;
}

glm::vec3 Mesh::getRotation()
{
    return rotation;
}
glm::vec3 Mesh::getScale()
{
    return scale;
}
void Mesh::setPostiton(glm::vec3 position)
{
    this->position = position;
}
void Mesh::setRotation(glm::vec3 rotation)
{
    this->rotation = rotation;
}
void Mesh::setScale(glm::vec3 scale)
{
    this->scale = scale;
}

void Mesh::translate(glm::vec3 translation)
{
    position += translation;
}
void Mesh::rotate(glm::vec3 translation)
{
    rotation += translation;
}
void Mesh::scaling(glm::vec3 translation)
{
    scale += translation;
}

void Mesh::setUniformData(std::string uniformName, std::any uniformData)
{
    uniform[uniformName] = uniformData;
}
void Mesh::ApplyUniform()
{
    for (const auto &[name, value] : uniform)
    {
        if (value.type() == typeid(float))
        {
            std::cout << "float" << std::endl;
        }
        else if (value.type() == typeid(int))
        {
            std::cout << "int " << std::endl;
        }
        else if (value.type() == typeid(glm::vec3))
        {
            std::cout << "vec3" << std::endl;
        }
        else if (value.type() == typeid(glm::mat4))
        {
            std::cout << "mat4" << std::endl;
        }
        else
        {
            std::cout << "do data type" << std::endl;
        }
    }
}