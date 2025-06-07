#ifndef __BACKBONE_H__
#define __BACKBONE_H__

#include <SDL.h>

#include <cstddef>  // size_t

#include "main.h"  // yrc

namespace yg {

struct Game {
    Game() {}
    ~Game() {}

    yrc init();
    yrc run();

  private:
    SDL_Window *wind_;
    const size_t scrw_{800};
    const size_t scrh_{600};
};

}  // namespace yg

#endif  // __BACKBONE_H__
