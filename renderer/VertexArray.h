

#include "VertexBuffer.h"
#include "VertexBufferLayout.h"
#include "functions/Debug.h" 

class VertexArray
{
    private:
        unsigned int m_RendererID;

    public:
        VertexArray()
{
    GLCall( glGenVertexArrays(1, &m_RendererID) );
}

~VertexArray()
{
    GLCall( glDeleteVertexArrays(1, &m_RendererID) );
}

void AddBuffer(const VertexBuffer& vb, const VertexBufferLayout& layout)
{
    Bind();
    vb.Bind();
    const std::vector<VertexBufferElement> elements = layout.GetElements();
    unsigned int offset = 0;
    for (unsigned int i = 0; i < elements.size() ; i++)
    {
        const VertexBufferElement element = elements[i];
        GLCall( glEnableVertexAttribArray(i) );
        GLCall( glVertexAttribPointer(i, element.count, element.type, element.normalized,
                                      layout.GetStride(), INT2VOIDP(offset)) );
        offset += element.count * VertexBufferElement::GetSizeOfType(element.type);
    }
}

void Bind() const
{
    GLCall( glBindVertexArray(m_RendererID) );
}

void Unbind() const
{
    GLCall( glBindVertexArray(0) );
}
};
