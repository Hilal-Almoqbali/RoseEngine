#include "functions/Debug.h"

class IndexBuffer
{
    private:
            unsigned int m_RendererID;
            unsigned int m_Count;

    public:
        IndexBuffer(const unsigned int* indices, unsigned int count)
          :
            m_Count(count)
        {
            ASSERT(sizeof(unsigned int) == sizeof(GLuint));

            GLCall( glGenBuffers(1, &m_RendererID) );
            GLCall( glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_RendererID) );
            GLCall( glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(unsigned int), indices, GL_STATIC_DRAW) );
        }

        ~IndexBuffer()
        {
            GLCall( glDeleteBuffers(1, &m_RendererID) );
        }

        void Bind() const
        {
            GLCall( glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_RendererID) );
        }

        void Unbind() const
        {
            GLCall( glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0) );
        }


                inline unsigned int GetCount() const { return m_Count; }
        };
