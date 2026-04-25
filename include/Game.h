#ifndef GAME_H
#define GAME_H

#include "FrameTimer.h"

#include <string_view>
#include <memory>

namespace GPlay::Core {

class Game {

  bool m_IsRunning  {false};
  std::unique_ptr<FrameTimer> m_GameTimer;

public:
  struct WindowDesc {
    int Width                   {0};
    int Height                  {0};
    std::string_view WindowName {""};
    int FPS                     {60};
  };


  Game(std::unique_ptr<FrameTimer>);

  void Initialize(const WindowDesc& desc);

  void Run();
  void PollInput();
  void UpdateState(double deltaTime);
  void RenderScreen();

  inline bool IsRunning() const     { return m_IsRunning; }

};

} // GPlay::Core


#endif // GAME_H Guard
