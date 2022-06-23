
#include <glad/glad/glad.h>
#include <GLFW/glfw3.h>
#include <fstream>
#include <sstream>
#include <string>
#include <iostream>
#include <cmath>

struct ShadderSource
{
    std::string vertexSource;
    std::string fragmentSource;
};

static unsigned int Compile(const char* source,unsigned int type);
static unsigned int Link(unsigned int vertexShader,unsigned int fragmentShader);
static ShadderSource read(const std::string& filePath);

unsigned int CompileShadder(const std::string filePath)
{
    ShadderSource shader = read(filePath);
    std::cout<< "\nvertex shadder:\n" <<shader.vertexSource
             <<"\nfragment shadder:\n"<<shader.fragmentSource<<std::endl;
    unsigned int Vshader = Compile(shader.vertexSource.c_str(),GL_VERTEX_SHADER);
    unsigned int Fshader = Compile(shader.fragmentSource.c_str(),GL_FRAGMENT_SHADER);
    unsigned int ShaderProgram = Link(Vshader,Fshader);
    return ShaderProgram;
}

static unsigned int Compile(const char* source,unsigned int type)
{
    unsigned int id = glCreateShader(type);
    const char* src = source;
    glShaderSource(id, 1,& src, NULL);
    glCompileShader(id);
    // check for shader compile errors
    int success;
    char infoLog[512];
    glGetShaderiv(id, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(id, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::"<<(type == GL_VERTEX_SHADER ? "vertex" : "fragment")<<"::COMPILATION_FAILED\n" << infoLog << std::endl;
    }
    return id;
}

static unsigned int Link(unsigned int vertexShader,unsigned int fragmentShader)
{
    // link shaders
    unsigned int shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);
    // check for linking errors
    /*glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
    }*/
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
    return shaderProgram;
}

static struct ShadderSource read(const std::string& filePath)
{
    enum class ShaderType
    {
        NONE = -1, VERTEX = 0, FRAGMENT = 1
    };

    std::ifstream stream(filePath);
    std::string line;
    std::stringstream ss[2];
    ShaderType type = ShaderType::NONE;

    while (getline(stream, line))
    {
        if (line.find("#shader") != std::string::npos)
        {
            if (line.find("vertex") != std::string::npos)
                type = ShaderType::VERTEX;
            else if (line.find("fragment") != std::string::npos)
                type = ShaderType::FRAGMENT;
        }
        else
        {
            ss[(int)type] << line << '\n';
        }
    }

    return { ss[0].str(), ss[1].str() };
}
