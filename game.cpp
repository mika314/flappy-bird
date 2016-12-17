#include "game.hpp"
#include "load_texture.hpp"

Game::Game(SDL_Renderer *renderer):
  renderer(renderer),
  tubeTexture(loadTexture(renderer, "tube.bmp")),
  digitsTexture(loadTexture(renderer, "digits.bmp")),
  bird(renderer)
{
}

Game::~Game()
{
  SDL_DestroyTexture(tubeTexture);
  SDL_DestroyTexture(digitsTexture);
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
    drawTubeCounter();
    SDL_RenderPresent(renderer);
  }
  return 0;
}

void Game::drawTubeCounter()
{
  int num = (counter - 4 * (Application::Width - bird.x)) / 2000 + 1;
  if (num < 0)
    num = 0;
  SDL_Rect srcRect;
  srcRect.y = 0;
  srcRect.w = 34;
  srcRect.h = 64;
  SDL_Rect destRect;
  destRect.x = Application::Width - 32 - 50;
  destRect.y = 50;
  destRect.w = 34;
  destRect.h = 64;
  do
  {
    srcRect.x = num % 10 * 34;
    num /= 10;
    SDL_RenderCopy(renderer, digitsTexture, &srcRect, &destRect);
    destRect.x -= 34;
  } while (num > 0);
}
