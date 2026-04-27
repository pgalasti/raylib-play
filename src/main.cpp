#include "Game.h"
#include "FrameTimer.h"
#include "renderer/RaylibRenderer.h"

#include <iostream>
#include <memory>

using namespace GPlay::Core;
using namespace GPlay::Renderer;

int main(int argc, char** argv) {

  std::unique_ptr<Game> game 
	  = std::make_unique<Game>(
			    std::make_unique<RLFrameTimer>(),
			    std::make_unique<RaylibRenderer>()
			  );

  Game::WindowDesc windowDescription {
    .Width      {1200}, 
    .Height     {800},
    .WindowName {"Test"},
    .FPS        {60}
  };
  game->Initialize(windowDescription);

  game->Run();

  return 0;
}
