
#include "functions/Debug.h" 
#include "functions/CompileShader.h" 
#include <string>
#include <unordered_map>
#include <fstream>
#include <sstream>

struct ShaderProgramSource
{
    std::string VertexSource;
    std::string FragmentSource;
};

class Shader
{
    private:
        unsigned int m_RendererID;
        std::string m_FilePath;
        std::unordered_map<std::string, int> m_UniformLocationCache;

    public:
    Shader(const std::string& filepath)
    : m_FilePath(filepath), m_RendererID(0)
{
    m_RendererID = CompileShadder(filepath);

    GLCall( glUseProgram(m_RendererID) );
}

~Shader()
{
    GLCall( glDeleteProgram(m_RendererID) );
}

void Bind() const
{
    GLCall( glUseProgram(m_RendererID) );
}

void Unbind() const
{
    GLCall( glUseProgram(0) );
}

        // Set uniforms
void SetUniform1i(const std::string& name, int value)
{
    GLCall( glUniform1i(GetUniformLocation(name), value) );
}

void SetUniform1f(const std::string& name, float value)
{
    GLCall( glUniform1f(GetUniformLocation(name), value) );
}
void SetUniform4f(const std::string& name, float f0, float f1, float f2, float f3)
{
    GLCall( glUniform4f(GetUniformLocation(name), f0, f1, f2, f3) );
}

    private:

int GetUniformLocation(const std::string& name)
{
    if (m_UniformLocationCache.find(name) != m_UniformLocationCache.end())
        return m_UniformLocationCache[name];

    GLCall( int location = glGetUniformLocation(m_RendererID, name.c_str()) );
    if (location == -1)
        std::cout << "No active uniform variable with name " << name << " found" << std::endl;

    m_UniformLocationCache[name] = location;

    return location;
}



};
