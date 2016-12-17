#pragma once
#include "application.hpp"
#include <SDL.h>

class Bird
{
public:
  Bird(SDL_Renderer *renderer);
  ~Bird();
  void tick(bool isMouseDown);
  void draw();
  float y = Application::Height / 2 - 50;
  const float x = Application::Width / 4 - 50;
private:
  SDL_Renderer *renderer;
  SDL_Texture *bird1;
  SDL_Texture *bird2;
  float v = 0.0f;
};
