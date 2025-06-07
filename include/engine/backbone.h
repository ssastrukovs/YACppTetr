#ifndef __ENGINE_BACKBONE_H__
#define __ENGINE_BACKBONE_H__

#include <SDL.h>

#include <cstddef>  // size_t

#include "engine/state.h"
#include "main.h"  // yrc

namespace yg {

struct Game {
    Game() {}
    ~Game();

    yrc run();

  private:
    SDL_Window *wind_;
    const size_t scrw_{800};
    const size_t scrh_{600};

    yrc init();
    yrc loop();
    yrc process_input(State& state);
};

}  // namespace yg

#endif  // __ENGINE_BACKBONE_H__
