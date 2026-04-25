#include "Game.h"
#include "FrameTimer.h"

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

    std::cout << delta << std::endl;
  }

}

void Game::PollInput() {

}

void Game::UpdateState(double deltaTime) {
  m_IsRunning = !WindowShouldClose();
  if(!m_IsRunning)
    return;
}

void Game::RenderScreen() {
  BeginDrawing();
  DrawText("Should see this window", 0, 0, 50, LIGHTGRAY);
  EndDrawing();
}
