#pragma once
#include <SDL.h>

class Application
{
public:
  static const auto Width = 1280;
  static const auto Height = 720;
  Application();
  int exec();
private:
  SDL_Window *window;
  SDL_Renderer *renderer;
};
