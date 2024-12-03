#include "UserInterface.h"
#include <imgui.h>
#include <backends/imgui_impl_glfw.h>
#include <backends/imgui_impl_opengl3.h>
#include <implot.h> 
#include <GLFW/glfw3.h>


bool InitializeUI(GLFWwindow* window)
{
    // ImGui
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO();
    (void)io;
    io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;
    ImGui::StyleColorsDark();
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init("#version 460");

    // ImPlot
    ImPlot::CreateContext();
	return false;
}

void RenderUI()
{
}

bool ShutDownUI()
{
	return false;
}
