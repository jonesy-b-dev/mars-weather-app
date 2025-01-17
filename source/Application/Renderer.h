#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <filesystem>

class Renderer
{
public:
	GLFWwindow* Initialize(int width, int height);
	bool Update(GLuint EBO);
	bool Shutdown();
	GLuint LoadBackground(std::filesystem::path pathToTexture);
	void RenderImage(GLuint texture);

	GLuint m_texture;


private:
	GLFWwindow* window;
};

