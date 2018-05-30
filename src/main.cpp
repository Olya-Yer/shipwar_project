#include <iostream>     // std::cout
#include <algorithm>    // std::min
#include "shipwar.hpp"
#include "assert.h"


int main(){
	Shipwar *game = new Shipwar();
                game->play();
        std::cout << "game is over. All ships are shut" << '\n';
        delete game;
	return 0;
}
