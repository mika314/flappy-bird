#pragma once
#include "application.hpp"
#include <SDL.h>

class Tube
{
public:
  Tube(SDL_Renderer *renderer, SDL_Texture *texture, int y, bool isUp);
  void tick();
  void draw();
private:
  SDL_Renderer *renderer;
  SDL_Texture *texture;
public:
  float x = Application::Width + 128;
  float y;
  bool isUp;
};
