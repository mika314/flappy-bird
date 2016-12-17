#pragma once
#include "bird.hpp"
#include "tube.hpp"
#include <SDL.h>
#include <vector>

class Game
{
public:
  Game(SDL_Renderer *renderer);
  ~Game();
  int exec();
private:
  SDL_Renderer *renderer;
  SDL_Texture *tubeTexture;
  SDL_Texture *digitsTexture;
  Bird bird;
  std::vector<Tube> tubeList;
  bool tick(bool isMouseDown);
  int counter = 0;
  void drawTubeCounter();
};
