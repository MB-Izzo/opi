#include <glad/glad.h>
#include <iostream>
#include <memory>
#include "opiEngine/Application.h"

namespace Opi
{

void framebuffer_size_callback(GLFWwindow *window, int width, int height)
{
  glViewport(0, 0, width, height);
}

void processInput(GLFWwindow *window)
{
  if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
    glfwSetWindowShouldClose(window, true);
}

Application::Application() { m_window = std::make_unique<OpiWindow>(); }

void Application::PushLayer() {}

int Application::Run()
{
  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
  {
    std::cout << "Failed to initialize GLAD" << std::endl;
    return -1;
  }

  glViewport(0, 0, 800, 600);
  glfwSetFramebufferSizeCallback(m_window->GetGLFWWindow(),
                                 framebuffer_size_callback);

  while (!glfwWindowShouldClose(m_window->GetGLFWWindow()))
  {
    processInput(m_window->GetGLFWWindow());

    // Rendering commands here

    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glfwSwapBuffers(m_window->GetGLFWWindow());
    glfwPollEvents();
  }

  glfwTerminate();
  return 0;
}

} // namespace Opi
