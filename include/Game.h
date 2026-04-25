#ifndef GAME_H
#define GAME_H

#include <string_view>

namespace GPlay::Core {

class Game {

  bool m_IsRunning  {false};

public:
  struct WindowDesc {
    int Width                   {0};
    int Height                  {0};
    std::string_view WindowName {""};
  };

  void Initialize(const WindowDesc& desc);

  void Run();
  void PollInput();
  void UpdateState(double deltaTime);
  void RenderScreen();

  inline bool IsRunning() const     { return m_IsRunning; }

};

} // GPlay::Core


#endif // GAME_H Guard
