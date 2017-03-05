#pragma once
#include "application.hpp"
#include "sdlpp.hpp"

class Tube
{
public:
  Tube(sdl::Renderer &renderer, sdl::Texture &texture, int y, bool isUp);
  void tick();
  void draw();
private:
  sdl::Renderer &renderer;
  sdl::Texture &texture;
public:
  float x = Application::Width + 128;
  float y;
  bool isUp;
};
