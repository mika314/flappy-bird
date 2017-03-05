#include "tube.hpp"
#include <stdexcept>
#include <string>

Tube::Tube(sdl::Renderer &renderer, sdl::Texture &texture, int y, bool isUp):
  renderer(renderer),
  texture(texture),
  y(y),
  isUp(isUp)
{}

void Tube::tick()
{
  x -= 0.25f;
}

void Tube::draw()
{
  if (!isUp)
  {
    SDL_Rect r;
    r.x = x - 128;
    r.y = y; 
    r.w = 256;
    r.h = 720;
    renderer.copyEx(&texture, nullptr, &r, 0, nullptr, SDL_FLIP_NONE);
  }
  else
  {
    SDL_Rect r;
    r.x = x - 128;
    r.y = y - Application::Height;
    r.w = 256;
    r.h = 720;
    renderer.copyEx(&texture, nullptr, &r, 0, nullptr, SDL_FLIP_VERTICAL);
  }
  
}
