#ifndef __ENGINE_BACKBONE_H__
#define __ENGINE_BACKBONE_H__

#include <SDL3/SDL.h>

#include <cstddef>  // size_t
#include <memory>

#include "engine/state.h"
#include "main.h"  // yrc

namespace yg {

struct Window {
    Window(const char *name, size_t w, size_t h);
    ~Window();
    Window(const Window &) = delete;
    Window(const Window &&) = delete;
    Window &operator=(const Window &) = delete;
    Window &operator=(const Window &&) = delete;

    bool valid() { return wind_; }

  private:
    SDL_Window *wind_;
    const char *nm_;
    size_t w_, h_;
};

struct Game {
    Game() = default;
    ~Game();
    Game(const Game &) = delete;
    Game(const Game &&) = delete;
    Game &operator=(const Game &) = delete;
    Game &operator=(const Game &&) = delete;

    yrc run();

  private:
    std::unique_ptr<Window> main_window_;
    const size_t scrw_{800};
    const size_t scrh_{600};

    yrc init();
    yrc loop();
    yrc process_input(State &state);
};

}  // namespace yg

#endif  // __ENGINE_BACKBONE_H__
