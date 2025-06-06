#include "main.h"

#include <GL/gl.h>
#include <SDL.h>
#include <SDL_video.h>

#include <iostream>

// yet (another) return code
typedef enum {
    YRC_ERROR = -1,
    YRC_OK = 0,
} yrc;

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
    yrc rc = game.init();
    if (rc == YRC_OK) {
        std::cout << "SDL init OK, running..." << std::endl;
        rc = game.run();
        if (rc == YRC_OK) {
            std::cout << "SDL run OK" << std::endl;
        } else {
            std::cout << "SDL run failed:" << SDL_GetError() << std::endl;
        }
    } else {
        std::cout << "Failed to init SDL: " << SDL_GetError() << std::endl;
    }
    int a;
    std::cout << "Send any key to shell to exit..." << std::endl;
    std::cin >> a;
    return 0;
}
