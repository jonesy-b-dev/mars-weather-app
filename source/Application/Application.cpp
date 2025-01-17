#include "Application.h"
#include <iostream>
#include <stb_image.h>

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
        return false;
    }
    glfwMakeContextCurrent(m_window);
   // glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    // glad: load all OpenGL function pointers
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return false;
    }

	glViewport(0, 0, width, height);

    //Create shaders

	// Initialize buffers
	// Vertex data
	float vertices[] = {
		// Positions    // Texture Coords
		-1.0f, -1.0f,  0.0f, 0.0f,
         1.0f, -1.0f,  1.0f, 0.0f,
         1.0f,  1.0f,  1.0f, 1.0f,
        -1.0f,  1.0f,  0.0f, 1.0f
    };

    unsigned int indices[] = {
        0, 1, 2,
        0, 2, 3
    };
    // Create VAO, VBO, and EBO
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)(2 * sizeof(float)));
    glEnableVertexAttribArray(1);

	mainShader = new Shader("shaders/vertex.vert", "shaders/fragment.frag");
    mainShader->use();
	// Initialize user interface
	m_baseUI.InitializeUI(m_window, &m_mainController);

// Set the sampler uniform to use texture unit 0

    // Load initial texture
    int textureID = mainRenderer.LoadBackground("Assets/cat.png");
    mainShader->setInt("texture1", textureID);
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
        if (!mainRenderer.Update(EBO))
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
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteBuffers(1, &EBO);
    m_baseUI.ShutDownUI();
    glfwTerminate();
}

void Application::ProcessInput(GLFWwindow* window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
    {
        glfwSetWindowShouldClose(window, true);
    }
	if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS) {
	    mainRenderer.LoadBackground("Assets/tom.jpg");
	}
}
