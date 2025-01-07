#include "Application.h"
#include <iostream>


bool Application::Start(int width, int height)
{
 //   m_window = mainRenderer.Initialize(width, height);

  //  if (m_window = nullptr)
  //  {
  //      std::cerr << "Failed to initialize the rendereer\n";
  //      return false;
  //  }


    /// NON EXTRACTED CODE IDK WHY THIS DOES WORK

	// glfw: initialize and configure
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // glfw window creation
    m_window = glfwCreateWindow(width, height, "LearnOpenGL", NULL, NULL);
    if (m_window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return nullptr;
    }
    glfwMakeContextCurrent(m_window);
   // glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    // glad: load all OpenGL function pointers
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return false;
    }

    // Get initial data from weather API

    // Initialize user interface
    m_baseUI.InitializeUI(m_window, &m_mainController);

    // Initialize textures

    return true;
}

void Application::Update()
{
    // Render loop
    while (!glfwWindowShouldClose(GetWindow()))
    {
        // input
        ProcessInput(GetWindow());

        // render
        if (!mainRenderer.Update())
        {
            std::cerr << "Application update loop failed, exiting....\n";
            break;
        }

        m_baseUI.RenderUI();
        // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
        glfwSwapBuffers(GetWindow());
        glfwPollEvents();
    }

}

void Application::Shutdown()
{
    mainRenderer.Shutdown();
    m_baseUI.ShutDownUI();
    glfwTerminate();
}

void Application::ProcessInput(GLFWwindow* window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
    {
        glfwSetWindowShouldClose(window, true);
    }
}
