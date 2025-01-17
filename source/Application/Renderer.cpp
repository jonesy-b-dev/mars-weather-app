#include "Renderer.h"
#include <iostream>
#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

void framebuffer_size_callback(GLFWwindow* window, int width, int height);

GLFWwindow* Renderer::Initialize(int width, int height)
{
	//// glfw: initialize and configure
    //glfwInit();
    //glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    //glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    //glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    //// glfw window creation
    //window = glfwCreateWindow(width, height, "LearnOpenGL", NULL, NULL);
    //if (window == NULL)
    //{
    //    std::cout << "Failed to create GLFW window" << std::endl;
    //    glfwTerminate();
    //    return nullptr;
    //}
    //glfwMakeContextCurrent(window);
    //glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    //// glad: load all OpenGL function pointers
    //if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    //{
    //    std::cout << "Failed to initialize GLAD" << std::endl;
    //    return nullptr;
    //}
	//return window;
    return NULL;
}

bool Renderer::Update(GLuint EBO)
{
    // Render
    glClear(GL_COLOR_BUFFER_BIT);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    RenderImage(m_texture);
	return true;
}

bool Renderer::Shutdown()
{
	return false;
}

GLuint Renderer::LoadBackground(std::filesystem::path pathToTexture)
{
    GLuint texture;
    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);

    // Set texture parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    int width, height, nrChannels;
    std::string pathS = pathToTexture.string();
    unsigned char* data = stbi_load(pathS.c_str() , &width, &height, &nrChannels, 0);
    if (data)
    {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
    } 
    else 
    {
        std::cerr << "Failed to load texture: " << pathToTexture << std::endl;
    }
    stbi_image_free(data);
    m_texture = texture;
    return texture;
}

void Renderer::RenderImage(GLuint texture)
{
    glBindTexture(GL_TEXTURE_2D, m_texture);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}

// glfw: whenever the window size changed (by OS or user resize) this callback function executes
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    // make sure the viewport matches the new window dimensions; note that width and 
    // height will be significantly larger than specified on retina displays.
    glViewport(0, 0, width, height);
}   

