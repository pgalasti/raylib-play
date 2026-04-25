#include "Game.h"

#include <iostream>
#include <memory>

using namespace GPlay::Core;

int main(int argc, char** argv) {

  std::unique_ptr<Game> game = std::make_unique<Game>(Game{});

  Game::WindowDesc windowDescription {
    .Width      {800}, 
    .Height     {450},
    .WindowName {"Test"}
  };
  game->Initialize(windowDescription);

  game->Run();
  while(game->IsRunning()) {
    
    game->PollInput();

    game->UpdateState(0.0);

    game->RenderScreen();

  }


  return 0;
}
