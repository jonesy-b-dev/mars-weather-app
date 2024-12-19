#pragma once
#include <GLFW/glfw3.h>
#include "WeatherController.h"
class UserInterface
{
public:
	bool InitializeUI(GLFWwindow* window, WeatherController* controller);
	void RenderUI();
	void ShutDownUI();
	
private:
	WeatherController* baseConstroller;
	
	// Windows
	void ApiKeyWindow();
	void TemperatureBars();
};
