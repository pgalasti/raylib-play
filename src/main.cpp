#include "Game.h"
#include "FrameTimer.h"

#include <iostream>
#include <memory>

using namespace GPlay::Core;

int main(int argc, char** argv) {

  std::unique_ptr<Game> game = std::make_unique<Game>(Game{std::make_unique<RLFrameTimer>()});

  Game::WindowDesc windowDescription {
    .Width      {800}, 
    .Height     {450},
    .WindowName {"Test"},
    .FPS        {60}
  };
  game->Initialize(windowDescription);

  game->Run();

  return 0;
}
