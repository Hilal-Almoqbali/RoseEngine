
//TODO: add precompiled headers and include them here

struct Mesh
{
    unsigned int index = 0;
    std::vector<float> vertices;
    std::vector<unsigned int> indices;
};

class VAO
{
    public:
        void AddMesh(Mesh input)
        {
            m_MeshArray.push_back(input);
        }
        void RemoveMesh(unsigned int index)
        {
            m_MeshArray.erase(index);
            resort_mesh_indices();
        }
        void Bind(unsigned int index)
        {
            //allocate buffers
            allocate_the_buffers();
            glGenVertexArrays(m_MeshArray.size, &VAO);
            glGenBuffers(m_MeshArray.size, &VBO);
            glGenBuffers(m_MeshArray.size, &EBO);
            //sign buffers
            glBindVertexArray(VAO);
            glBindBuffer(GL_ARRAY_BUFFER, VBO);
            glBufferData(GL_ARRAY_BUFFER, sizeof(m_MeshArray.at(index).vertices), vertices, GL_STATIC_DRAW);
            glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
            glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(m_MeshArray.at(index).indices), indices, GL_STATIC_DRAW);
            glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
            //bind buffer
            glEnableVertexAttribArray(0);
            glBindBuffer(GL_ARRAY_BUFFER, 0); 
            glBindVertexArray(0);
        }
        void BindAll()
        {
            for(auto i : m_MeshArray)
            {
                Bind(i.index);
            }
        }
    private:
    std::vector<unsigned int> VBO, VAO, EBO;
    std::vector<Mesh> m_MeshArray;
    void allocate_the_buffers()
    {
        VBO.resize(m_MeshArray.size);
        VAO.resize(m_MeshArray.size);
        EBO.resize(m_MeshArray.size);
    }
    void resort_mesh_indices()
    {
        unsigned int count 0; 
        for (auto i : m_MeshArray )
        {
            i.index = count;
            count++;
        }
    }
};