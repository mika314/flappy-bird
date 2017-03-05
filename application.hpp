#pragma once
#include "sdlpp.hpp"

class Application
{
public:
  static const auto Width = 1280;
  static const auto Height = 720;
  Application();
  int exec();
private:
  sdl::Init init;
  sdl::Window window;
  sdl::Renderer renderer;
};
