#include "Game.h"
#include "FrameTimer.h"
#include "core/Event.h"

#include <raylib.h>

#include <memory>
#include <iostream> // Remove

using namespace GPlay::Core;

Game::Game(std::unique_ptr<FrameTimer> gameTimer) : m_GameTimer{std::move(gameTimer)} {

}

void Game::Initialize(const Game::WindowDesc& windowDescription) {
  auto [width, height, windowTitle, fps] = windowDescription;
  InitWindow(width, height, windowTitle.data());

  SetTargetFPS(fps);
}

void Game::Run() {
  m_IsRunning = true;

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
  static size_t id{0};

  static float x{0.0f};

  x += (deltaTime*10);
  m_EventQueue.emplace(EntityMovementPayload{++id, x, 10.0f});
  std::cout << x << std::endl; 

}

void Game::RenderScreen() {
  BeginDrawing();
  
  DrawText("Should see this window", 0, 0, 50, LIGHTGRAY);

  if (!m_EventQueue.empty()) {
    Event event = m_EventQueue.front();
    m_EventQueue.pop();

    Vector2 deltaCircle = { event.payload().x, 800.0f/3.0f };
    DrawCircleV(deltaCircle, 32, RED);
  }

  EndDrawing();
}

void Game::Cleanup() {

  while(!m_EventQueue.empty())
    m_EventQueue.pop();
}
