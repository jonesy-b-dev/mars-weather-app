#pragma once
#define GLFW_INCLUDE_NONE
#include "UserInterface.h"
#include "WeatherController.h"
#include "Renderer.h"
#include <GLFW/glfw3.h>
#include "shader.h"

class Application
{
public:
	bool Start(int width, int height);
	void Update();
	void Shutdown();
	GLFWwindow* GetWindow() { return m_window; };
private:
	void ProcessInput(GLFWwindow* window);
    GLuint VAO, VBO, EBO;


private:
	GLFWwindow* m_window;
	Renderer mainRenderer;
	WeatherController m_mainController;
	UserInterface m_baseUI;
	Shader* mainShader;
	int textureID;
};

