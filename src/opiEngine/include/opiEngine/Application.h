#include "opiEngine/Core/AppLayer.h"

namespace Opi {

class Application {
public:
  void PushLayer();
  int Run();

private:
  AppLayer* m_layer;
};

} // namespace Opi
