#include "game.hpp"
#include "load_texture.hpp"

Game::Game(SDL_Renderer *renderer):
  renderer(renderer),
  tubeTexture(loadTexture(renderer, "tube.bmp")),
  bird(renderer)
{
}

Game::~Game()
{
  SDL_DestroyTexture(tubeTexture);
}


bool Game::tick(bool isMouseDown)
{
  if (counter++ % 2000 == 0)
  {
    auto y = rand() % (Application::Height - 200 - 250 - 100) + 100;
    tubeList.emplace_back(renderer, tubeTexture, y + 250, false);
    tubeList.emplace_back(renderer, tubeTexture, y, true);
  }
  bird.tick(isMouseDown);
  SDL_Rect birdRect;
  birdRect.x = bird.x - 114 / 2;
  birdRect.y = bird.y - 94 / 2;
  birdRect.w = 114;
  birdRect.h = 94;
  SDL_Rect res;
  for (auto &tube: tubeList)
  {
    tube.tick();
    SDL_Rect tubeRect;
    tubeRect.x = tube.x - 128 + 20;
    tubeRect.w = 256 - 40;
    tubeRect.h = 10000;
    if (tube.isUp)
    {
      tubeRect.y = tube.y - 10000;
      if (SDL_IntersectRect(&birdRect, &tubeRect, &res))
      {
        return false;
      }
    }
    else
    {
      tubeRect.y = tube.y;
      if (SDL_IntersectRect(&birdRect, &tubeRect, &res))
      {
        return false;
      }
    }
  }
  for (auto iter = std::begin(tubeList); iter != std::end(tubeList); )
  {
    if (iter->x < -128)
      iter = tubeList.erase(iter);
    else
      ++iter;
  }
  return bird.y < Application::Height;
}


int Game::exec()
{
  auto oldTick = SDL_GetTicks();
  bool isMouseDown = false;
  for (auto done = false; !done;)
  {
    SDL_Event e;
    if (SDL_PollEvent(&e))
    {
      switch (e.type)
      {
      case SDL_MOUSEBUTTONDOWN:
        isMouseDown = true;
        break;
      case SDL_MOUSEBUTTONUP:
        isMouseDown = false;
        break;
      case SDL_QUIT:
        done = true;
        break;
      }
    }

    auto currentTick = SDL_GetTicks();
    for (auto i = oldTick; i < currentTick; ++i)
    {
      if (!tick(isMouseDown))
      {
        SDL_Delay(4000);
        return 1;
      }
    }
    oldTick = currentTick;
    
    SDL_SetRenderDrawColor(renderer, 0x00, 0xff, 0xff, 0xff);
    SDL_RenderClear(renderer);
    bird.draw();
    for (auto &tube: tubeList)
      tube.draw();
    SDL_RenderPresent(renderer);
  }
  return 0;
}
