#include <glad/glad.h>

#include "opiEngine/Application.h"
#include "opiEngine/Core/Logger.h"

#ifdef TRACY_ENABLE
#include "tracy/Tracy.hpp"
#include "tracy/TracyOpenGL.hpp"
#endif

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

Application::Application()
{
  Logger::Init();
  OPI_CORE_INFO("Launching engine");
  m_window = std::make_unique<OpiWindow>();
  OPI_CORE_INFO("Created window");
}

void Application::PushLayer() {}

int Application::Run()
{
  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
  {
    OPI_CORE_ERROR("Failed to initialize GLAD");
    return -1;
  }
#ifdef TRACY_ENABLE
  TracyGpuContext;
#endif

  glViewport(0, 0, 800, 600);
  glfwSetFramebufferSizeCallback(m_window->GetGLFWWindow(),
                                 framebuffer_size_callback);

  while (!glfwWindowShouldClose(m_window->GetGLFWWindow()))
  {
#ifdef TRACY_ENABLE
    ZoneScoped;
    TracyGpuZone("Frame");
#endif

    processInput(m_window->GetGLFWWindow());

    // Rendering commands here

    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glfwSwapBuffers(m_window->GetGLFWWindow());
    glfwPollEvents();

#ifdef TRACY_ENABLE
    FrameMark;
    TracyGpuCollect;
#endif
  }

  glfwTerminate();
  return 0;
}
} // namespace Opi
