#pragma once

#include "opiEngine/Core/AppLayer.h"
#include "opiEngine/Renderer/Window.h"
#include <GLFW/glfw3.h>

namespace Opi
{

class Application
{
public:
  Application();
  void PushLayer();
  int Run();

private:
  AppLayer *m_layer;
  std::unique_ptr<OpiWindow> m_window;
};

} // namespace Opi
