#include "application.hpp"
#include "game.hpp"
#include <stdexcept>
#include <string>

Application::Application():
  init(SDL_INIT_EVERYTHING),
  window("Flappy bird", 65, 126, Width, Height, SDL_WINDOW_BORDERLESS),
  renderer(&window, -1, 0)
{
}

int Application::exec()
{
  for (;;)
  {
    Game g(renderer);
    if (g.exec() == 0)
      break;
  }
  return 0;
}
