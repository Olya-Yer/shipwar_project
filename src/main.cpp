#include <iostream>     // std::cout
#include <algorithm>    // std::min
#include "shipwar.hpp"
#include "assert.h"


int main(){
        Shipwar *game = new Shipwar();
        if ( NULL == game) {
                std::abort();
        }
        game->play();
        std::cout << "game is over. All ships are shooted" << '\n';
        delete game;
        return 0;
}
