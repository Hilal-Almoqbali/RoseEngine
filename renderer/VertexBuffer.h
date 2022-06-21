#pragma once

class VertexBuffer
{
    private:
        unsigned int m_RendererID;

    public:
VertexBuffer(const void* data, unsigned int size)
{
    GLCall( glGenBuffers(1, &m_RendererID) );
    GLCall( glBindBuffer(GL_ARRAY_BUFFER, m_RendererID) );
    GLCall( glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW) );
}

~VertexBuffer()
{
    GLCall( glDeleteBuffers(1, &m_RendererID) );
}

void Bind() const
{
    GLCall( glBindBuffer(GL_ARRAY_BUFFER, m_RendererID) );
}

void Unbind() const
{
    GLCall( glBindBuffer(GL_ARRAY_BUFFER, 0) );
}
};
