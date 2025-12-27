#include "SDL3/SDL.h"

#include "symphony_lite/vector3d.hpp"

#include <iostream>

static const int kScreenWidth = 480;
static const int kScreenHeight = 272;
bool game_running = true;

void mainloop() {
  SDL_Event event;
  while (SDL_PollEvent(&event)) {
    switch (event.type) {
      case SDL_EVENT_QUIT:
        game_running = false;
        break;
      default:
        break;
    }
  }
}

int main(int argc, char* argv[]) {
  std::cout << "Running PSP stereo demo" << std::endl;

  SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_GAMEPAD);
  SDL_CreateWindow("window", kScreenWidth, kScreenHeight, 0);

  while (game_running) {
    mainloop();
  }

  return 0;
}
