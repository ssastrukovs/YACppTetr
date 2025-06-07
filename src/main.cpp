#include "main.h"

#include <GL/gl.h>
#include <SDL.h>
#include <SDL_video.h>

#include <iostream>

#include "util/logger.h"

struct Game {
    Game() {}
    ~Game() {}

    yrc init() {
        yrc rc = SDL_Init(SDL_INIT_EVERYTHING) ? YRC_ERROR : YRC_OK;
        return rc;
    }
    yrc run() {
        // TODO: test on non-vulkan gpu?
        wind_ = SDL_CreateWindow("YATetr", SDL_WINDOWPOS_CENTERED,
                                 SDL_WINDOWPOS_CENTERED, scrw_, scrh_,
                                 SDL_WINDOW_VULKAN);
        return wind_ != NULL ? YRC_OK : YRC_ERROR;
    }

  private:
    SDL_Window *wind_;
    const size_t scrw_{800};
    const size_t scrh_{600};
};

int main(int argc, char *argv[]) {
    std::cout << "Hello, from YATetr1!\n";

    Game game;
    YRCL_SDL(game.init());
    YRCL_SDL(game.run());
    int a;
    std::cout << "Send any key to shell to exit..." << std::endl;
    std::cin >> a;
    return 0;
}
