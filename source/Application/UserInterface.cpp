#include "UserInterface.h"
#include "WeatherController.h"

#include <imgui.h>
#include <backends/imgui_impl_glfw.h>
#include <backends/imgui_impl_opengl3.h>
#include <misc/cpp/imgui_stdlib.h>
#include <implot.h> 
#include <GLFW/glfw3.h>

bool m_showAPIkeyWindow = true;

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


void ApiKeyWindow()
{
    ImGui::Begin("Enter API Key", nullptr, ImGuiWindowFlags_NoResize);
    float availWidth = ImGui::GetContentRegionAvail().x;
    float totalWidth = 315.0f;
    float offset = (availWidth - totalWidth) * 0.5f;
    ImGui::SetCursorPosX(offset);
    ImGui::InputText("##API key", &WeatherController::m_api_key);
    ImGui::SameLine();
    if (ImGui::Button("Continue"))
    {
        std::cout << WeatherController::m_api_key;
        m_showAPIkeyWindow = false;
    }
    ImGui::End();
}

void RenderUI()
{
	// Render ImGui
	ImGui_ImplOpenGL3_NewFrame();
	ImGui_ImplGlfw_NewFrame();
	ImGui::NewFrame();
    ImGui::DockSpaceOverViewport(ImGuiDockNodeFlags_None, ImGui::GetMainViewport());
	
	//ImGui::ShowDemoWindow();
	//ImPlot::ShowDemoWindow();
    if (m_showAPIkeyWindow)
    {
        ApiKeyWindow();
    }
	
	ImGui::Render();
	ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}


void ShutDownUI()
{
    // Cleanup
    ImGui_ImplGlfw_Shutdown();
    ImGui_ImplOpenGL3_Shutdown();
    ImPlot::DestroyContext();
    ImGui::DestroyContext();
}
