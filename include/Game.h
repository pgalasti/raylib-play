#ifndef GAME_H
#define GAME_H

#include "FrameTimer.h"
#include "core/Event.h"
#include "core/EventBus.h"
#include "game/Level.h"
#include "renderer/RaylibRenderer.h"

#include <string_view>
#include <memory>
#include <queue>


namespace GPlay::Core {
using namespace GPlay::Game;

class Game {

  bool m_IsRunning  {false};
  std::unique_ptr<FrameTimer> m_GameTimer;
  std::unique_ptr<GPlay::Renderer::Renderer> m_pRenderer;
  EventBus m_EventBus;
  std::queue<std::unique_ptr<Level>> m_Levels;     // Turn this into a formal manager. Maybe change to vector for reuse
  Level* m_pCurrentLevel {nullptr};

public:
  struct WindowDesc {
    int Width                   {0};
    int Height                  {0};
    std::string_view WindowName {""};
    int FPS                     {60};
  };


  Game(std::unique_ptr<FrameTimer>, std::unique_ptr<GPlay::Renderer::Renderer>);

  void Initialize(const WindowDesc& desc);

  void Run();
  void PollInput();
  void UpdateState(double deltaTime);
  void RenderScreen();
  void Cleanup();

  inline bool IsRunning() const     { return m_IsRunning; }

};

} // GPlay::Core


#endif // GAME_H Guard
