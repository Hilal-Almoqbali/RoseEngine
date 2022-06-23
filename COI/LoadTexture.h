#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

#include <glad/glad/glad.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

static char read(const std::string& filePath)
{
    enum class TextureType
    {
        NONE = -1, JPG = 0, PNG = 1
    };

    std::ifstream stream(filePath);
    std::string line;
    std::stringstream ss[2];
    TextureType type = TextureType::NONE;

    while (getline(stream, line))
    {
        if (line.find("#texture") != std::string::npos)
        {
            if (line.find("jpg") != std::string::npos)
                type = TextureType::JPG;
            else if (line.find("png") != std::string::npos)
                type = TextureType::PNG;
        }
        else
        {
            ss[(int)type] << line << '\n';
        }
    }

    std::string output = ss[(int)type].str();
    char* cpout= output.c_str();

}

unsigned int load (const char texPath)
{
    unsigned int texture;
glGenTextures(1, &texture);
glBindTexture(GL_TEXTURE_2D, texture);
// set the texture wrapping/filtering options (on the currently bound texture object)
glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	
glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
// load and generate the texture
int width, height, nrChannels;
unsigned char *data = stbi_load(&texPath, &width, &height, &nrChannels, 0);
if (data)
{
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
    glGenerateMipmap(GL_TEXTURE_2D);
}
else
{
    std::cout << "Failed to load texture" << std::endl;
}
stbi_image_free(data);
}