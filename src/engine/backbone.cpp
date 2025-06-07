
#include "engine/backbone.h"
// #include <GL/gl.h>
// #include <SDL_video.h>

namespace yg {

yrc Game::init() {
    yrc rc = SDL_Init(SDL_INIT_EVERYTHING) ? YRC_ERROR : YRC_OK;
    return rc;
}
yrc Game::run() {
    // TODO: test on non-vulkan gpu?
    wind_ = SDL_CreateWindow("YATetr", SDL_WINDOWPOS_CENTERED,
                             SDL_WINDOWPOS_CENTERED, scrw_, scrh_,
                             SDL_WINDOW_VULKAN);
    return wind_ != NULL ? YRC_OK : YRC_ERROR;
}

}  // namespace yg
