#include "bird.hpp"
#include "load_texture.hpp"
#include <stdexcept>

Bird::Bird(SDL_Renderer *renderer):
  renderer(renderer),
  bird1(loadTexture(renderer, "bird1.bmp")),
  bird2(loadTexture(renderer, "bird2.bmp"))
{
}

Bird::~Bird()
{
  SDL_DestroyTexture(bird1);
  SDL_DestroyTexture(bird2);
}


void Bird::draw()
{
  SDL_Rect r;
  r.x = x - 64;
  r.y = y - 64; 
  r.w = 128;
  r.h = 128;
  auto res = SDL_RenderCopyEx(renderer, SDL_GetTicks() % 300 > 150 ? bird1 : bird2, nullptr, &r, v * 50, nullptr, SDL_FLIP_NONE);
  if (res != 0)
    throw std::runtime_error(std::string("SDL_RenderCopy ") + SDL_GetError());
}

void Bird::tick(bool isMouseDown)
{
  v -= isMouseDown ? 0.003 : 0;
  v += 0.001;
  y += v;
}
