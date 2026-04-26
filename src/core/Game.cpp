#include "GDefines.h"
#include "Game.h"
#include "FrameTimer.h"
#include "core/Event.h"
#include "game/TestLevel.h"

#include <raylib.h>

#include <memory>
#include <iostream> // Remove

using namespace GPlay::Core;
using namespace GPlay::Game;

Game::Game(std::unique_ptr<FrameTimer> gameTimer) : m_GameTimer{std::move(gameTimer)} {
  m_Levels.push(std::make_unique<TestLevel>("Test Level", &m_EventBus));
  
  GLOG("Levels loaded:")
  GLOG(m_Levels.size())
}

void Game::Initialize(const Game::WindowDesc& windowDescription) {
  auto [width, height, windowTitle, fps] = windowDescription;
  InitWindow(width, height, windowTitle.data());

  SetTargetFPS(fps);
}

void Game::Run() {
  m_IsRunning = true;
  
  std::unique_ptr<Level> firstLevel = std::move(m_Levels.front());
  m_Levels.pop();
  m_pCurrentLevel = firstLevel.get();
  GLOG("Loading Level: ")
  GLOG(m_pCurrentLevel->GetName())

  m_pCurrentLevel->Init();
  m_pCurrentLevel->Load();

  // Probably move this to a Frame function or something.
  while(IsRunning()) {
    m_GameTimer->Tick();
    double delta {m_GameTimer->GetFrameTime()};
    PollInput();
    UpdateState(delta);
    RenderScreen();
  }

  Cleanup();

}

void Game::PollInput() {

}

void Game::UpdateState(double deltaTime) {
  m_IsRunning = !WindowShouldClose();
  if(!m_IsRunning)
    return;
	    
  if(m_pCurrentLevel->IsReady()) {
    m_pCurrentLevel->UpdateState(deltaTime);  
  }

}

void Game::RenderScreen() {
  BeginDrawing();
  
  DrawText("Should see this window", 0, 0, 50, LIGHTGRAY);

  m_EventBus.Invoke();
/*
  if (!m_EventQueue.empty()) {
    Event event = m_EventQueue.front();
    m_EventQueue.pop();

    std::visit([](const auto& e) {
      using T = std::decay_t<decltype(e)>;
      if constexpr (std::is_same_v<T, EntityMovementEvent>) {
        Vector2 deltaCircle = { e.x, 800.0f/3.0f };
        DrawCircleV(deltaCircle, 32, RED);
      }
    }, event);

  }
*/
  EndDrawing();
}

void Game::Cleanup() {

  GLOG("Event Bus Size on cleanup: ")
  GLOG(m_EventBus.Size())
  m_EventBus.Clear();
}
