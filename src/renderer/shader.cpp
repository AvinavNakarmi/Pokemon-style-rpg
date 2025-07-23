#include "shader.h"
std::string get_file_contents(const char *filename)
{
    std::ifstream in(filename, std::ios::binary);
    if (in)
    {
        std::string contents;
        in.seekg(0, std::ios::end);
        contents.resize(in.tellg());
        in.seekg(0, std::ios::beg);
        in.read(&contents[0], contents.size());
        in.close();
        return (contents);
    }
    throw(errno);
}
GLuint Shader::createShader(const char *shaderSource, GLenum type)
{
    int success;
    GLuint Shader = glCreateShader(type);
    glShaderSource(Shader, 1, &shaderSource, nullptr);
    glCompileShader(Shader);
    glGetShaderiv(Shader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        char infoLog[512];
        glGetShaderInfoLog(Shader, 512, nullptr, infoLog);
        std::cerr << "Fragment shader compilation failed:\n"
                  << infoLog << std::endl;
        throw(infoLog);
    }
    return Shader;
}
Shader::Shader(const char *vertexFile, const char *fragmentFile)
{
    try
    {

        std::string vertexCode = get_file_contents(vertexFile);
        std::string fragmentCode = get_file_contents(fragmentFile);
        const char *vertexSource = vertexCode.c_str();
        const char *fragmentSource = fragmentCode.c_str();
        GLuint vertexShader = this->createShader(vertexSource, GL_VERTEX_SHADER);
        GLuint fragmentShader = this->createShader(fragmentSource, GL_FRAGMENT_SHADER);
        ID = glCreateProgram();
        glAttachShader(ID, vertexShader);
        glAttachShader(ID, fragmentShader);
        glLinkProgram(ID);
        int success;
        glGetProgramiv(ID, GL_LINK_STATUS, &success);
        if (!success)
        {
            char infoLog[512];
            glGetProgramInfoLog(ID, 512, nullptr, infoLog);
            std::cerr << "Shader program linking failed:\n"
                      << infoLog << std::endl;
            throw(infoLog);
        }
        glDeleteShader(vertexShader);
        glDeleteShader(fragmentShader);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
}

void Shader::Use()
{
    glUseProgram(ID);
}

void Shader::Activate()
{
    glUseProgram(ID);
}

Shader::~Shader()
{
    glDeleteProgram(ID);
}