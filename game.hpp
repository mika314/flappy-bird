#pragma once
#include "bird.hpp"
#include "sdlpp.hpp"
#include "tube.hpp"
#include <memory>
#include <vector>

class Game
{
public:
  Game(sdl::Renderer &renderer);
  int exec();
private:
  sdl::Renderer &renderer;
  sdl::Texture tubeTexture;
  sdl::Texture digitsTexture;
  Bird bird;
  std::vector<std::unique_ptr<Tube>> tubeList;
  bool tick(bool isMouseDown);
  int counter = 0;
  void drawTubeCounter();
};
