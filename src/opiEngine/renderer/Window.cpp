#include "opiEngine/Renderer/Window.h"
#include "opiEngine/Core/Logger.h"

namespace Opi
{

OpiWindow::OpiWindow()
{
  glfwInit();
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

  m_window = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);

  OPI_CORE_ASSERT(m_window != NULL, "Window was not created");

  if (m_window == NULL)
  {
    glfwTerminate();
    return;
  }
  glfwMakeContextCurrent(m_window);
}

} // namespace Opi
