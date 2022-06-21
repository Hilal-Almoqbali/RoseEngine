

#include <GL/glew.h>

#include "Debug.h"
#include "VertexArray.h"
#include "IndexBuffer.h"
#include "Shader.h"

class Renderer
{
    public:
        void Clear() const
        {
            GLCall( glClear( GL_COLOR_BUFFER_BIT ) );
        }

        void Draw(const VertexArray& va, const IndexBuffer& ib, const Shader& shader) const
        {
            shader.Bind();
            va.Bind();
            ib.Bind();
            GLCall( glDrawElements(GL_TRIANGLES, ib.GetCount(), GL_UNSIGNED_INT, nullptr) );
        }
        
};
