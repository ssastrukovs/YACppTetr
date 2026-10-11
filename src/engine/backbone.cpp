
#include "engine/backbone.h"

#include "util/logger.h"

namespace yg {

Window::Window(const char *name, size_t w, size_t h) : nm_(name), w_(w), h_(h) {
    // TODO: test on non-vulkan gpu?
    wind_ = SDL_CreateWindow(nm_, w, h, SDL_WINDOW_VULKAN);
}

Window::~Window() { SDL_DestroyWindow(wind_); }

Game::~Game() { SDL_Quit(); }

yrc Game::init() {
    yrc rc = SDL_Init(SDL_INIT_VIDEO) ? yrc::OK : yrc::ERROR;
    main_window_ = std::make_unique<Window>("YaTetr", scrw_, scrh_);
    rc = main_window_->valid() ? yrc::OK : yrc::ERROR;
    return rc;
}

yrc Game::run() {
    yrc rc;
    YRCL_SDL(init());
    loop();
    return yrc::OK;
}

yrc Game::loop() {
    State state{State::NONE};
    while (state != State::EXIT) {
        process_input(state);
        SDL_Delay(4);  // roughly 240 Hz polling rate
    }
    return yrc::OK;
}

yrc Game::process_input(State &state) {
    SDL_Event e;

    if (SDL_PollEvent(&e)) {
        switch (e.type) {
        case SDL_EVENT_QUIT: {
            state = State::EXIT;
            break;
        }
        default: {
            break;
        }
        }
    }

    return yrc::OK;
}

}  // namespace yg
