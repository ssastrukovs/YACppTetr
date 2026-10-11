#include "main.h"

#include <SDL3/SDL_main.h>  // IWYU pragma: keep

#include <iostream>

#include "engine/backbone.h"

int main(int argc, char *argv[]) {
    std::cout << "Hello, from YATetr! Close the game to end program\n";

    yg::Game game;
    if (game.run() != yrc::OK) {
        std::cout << "Failed to run game" << std::endl;
        return -1;
    }
    std::cout << "Game exited successfully" << std::endl;

    return 0;
}
