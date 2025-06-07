
#include "engine/backbone.h"

#include "util/logger.h"

namespace yg {

Game::~Game() {
    SDL_DestroyWindow(wind_);
    SDL_Quit();
}

yrc Game::init() {
    yrc rc = SDL_Init(SDL_INIT_EVERYTHING) ? yrc::ERROR : yrc::OK;
    return rc;
}

yrc Game::run() {
    yrc rc;
    YRCL_SDL(init());
    // TODO: test on non-vulkan gpu?
    wind_ = SDL_CreateWindow("YATetr", SDL_WINDOWPOS_CENTERED,
                             SDL_WINDOWPOS_CENTERED, scrw_, scrh_,
                             SDL_WINDOW_VULKAN);
    rc = wind_ != NULL ? yrc::OK : yrc::ERROR;
    YRCL_SDL(rc);
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
        case SDL_QUIT: {
            state = State::EXIT;
            break;
        default: {
            break;
        }
        }
        }
    }

    return yrc::OK;
}

}  // namespace yg
