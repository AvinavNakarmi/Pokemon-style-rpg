class Transform
{
    static translate(glm::vec3 position)
    {
        glm::mat4 translationMatrix = glm::mat4(1.0f);
        translationMatrix = glm::translate(translationMatrix, position);
        return translationMatrix;
    }
};