#pragma once
#include <GLFW/glfw3.h>

namespace Opi
{

class OpiWindow
{
  public:
    OpiWindow();

  public:
    GLFWwindow *const GetGLFWWindow() const { return m_window; }

  private:
    GLFWwindow *m_window;
};

} // namespace Opi
