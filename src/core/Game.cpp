#include "Game.h"

#include "raylib.h"

using namespace GPlay::Core;

void Game::Initialize(const Game::WindowDesc& windowDescription) {
  auto [width, height, windowTitle] = windowDescription;
  InitWindow(width, height, windowTitle.data());

  SetTargetFPS(60); // Add to WindowDesc
}

void Game::Run() {
  m_IsRunning = true;
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
