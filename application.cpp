#include "application.hpp"
#include "game.hpp"
#include <stdexcept>

Application::Application()
{
  auto res = SDL_Init(SDL_INIT_EVERYTHING);
  if (res != 0)
    throw std::runtime_error(std::string("SDL_Init(SDL_INIT_EVERYTHING)") + SDL_GetError());
  SDL_CreateWindowAndRenderer(Width, Height, SDL_WINDOW_BORDERLESS, &window, &renderer);
  SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
  SDL_SetWindowPosition(window, 65, 126);
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
