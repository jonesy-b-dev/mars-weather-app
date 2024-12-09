#include <glad/glad.h>
#include "Application/Application.h"
#include <imgui.h>
#include <backends/imgui_impl_glfw.h>
#include <backends/imgui_impl_opengl3.h>

#include <implot.h> 

#include <iostream>

int main()
{
    Application app;

    if (!app.Start(1300, 900))
    {
        std::cerr << "Failed to start application\n";
        exit(1);
    }

    app.Update();

    return 0;
}
