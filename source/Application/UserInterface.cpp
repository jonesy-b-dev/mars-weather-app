#include "UserInterface.h"
#include "WeatherController.h"

#include <imgui.h>
#include <backends/imgui_impl_glfw.h>
#include <backends/imgui_impl_opengl3.h>
#include <misc/cpp/imgui_stdlib.h>
#include <implot.h> 
#include <GLFW/glfw3.h>

bool m_showAPIkeyWindow = true;

bool UserInterface::InitializeUI(GLFWwindow* window, WeatherController* controller)
{
    // Set the weather controller reference
    m_baseConstroller = controller;
    // ImGui
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO();
    (void)io;
    io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;
    ImGui::StyleColorsDark();

    // goes wrong here fsr
    ImGui_ImplGlfw_InitForOpenGL(window, true);

    ImGui_ImplOpenGL3_Init("#version 460");

    // ImPlot
    ImPlot::CreateContext();
	return false;
}

void UserInterface::RenderUI()
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
        SetupWindow();
    }
	
    // Only show other windows when api key is set
    if (!m_showAPIkeyWindow)
    {
        TemperatureBars();
    }
	ImGui::Render();
	ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}

void UserInterface::SetupWindow()
{
    ImGui::Begin("Enter API Key", nullptr, ImGuiWindowFlags_NoResize);
    float totalWidth = 315.0f;
    float availWidth = ImGui::GetContentRegionAvail().x;
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

void UserInterface::TemperatureBars()
{
    ImGui::Begin("Temperature Bars");
    do
    {
        m_baseConstroller->GetWeatherFromCoords2(5.4819610785150195, 51.43899078590969);
    }
    while (ImGui::Button("Refresh"));

    ImPlot::BeginPlot("Temperature");
    float xdata[4] = { 1, 2, 3, 4 };
    float ydata[4] = { 1, 2, 3, 4 };
    ImPlot::PlotBars("Temp in Celcius", xdata, 4);
    ImPlot::EndPlot();
    ImGui::End();
}


void UserInterface::ShutDownUI()
{
    // Cleanup
    ImGui_ImplGlfw_Shutdown();
    ImGui_ImplOpenGL3_Shutdown();
    ImPlot::DestroyContext();
    ImGui::DestroyContext();
}
