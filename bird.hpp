#pragma once
#include "application.hpp"
#include "sdlpp.hpp"

class Bird
{
public:
  Bird(sdl::Renderer &renderer);
  void tick(bool isMouseDown);
  void draw();
  float y = Application::Height / 2 - 50;
  const float x = Application::Width / 4 - 50;
private:
  sdl::Renderer &renderer;
  sdl::Texture bird1;
  sdl::Texture bird2;
  float v = 0.0f;
};
