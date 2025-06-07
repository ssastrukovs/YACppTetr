#include "main.h"

#include <iostream>

#include "engine/backbone.h"
#include "util/logger.h"

int main(int argc, char *argv[]) {
    std::cout << "Hello, from YATetr1!\n";

    yg::Game game;
    YRCL_SDL(game.init());
    YRCL_SDL(game.run());
    int a;
    std::cout << "Send any key to shell to exit..." << std::endl;
    std::cin >> a;
    return 0;
}
