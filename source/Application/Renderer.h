#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>

class Renderer
{
public:
	GLFWwindow* Initialize(int width, int height);
	bool Update();
	bool Shutdown();
};

