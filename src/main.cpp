#include <iostream>     // std::cout
#include <algorithm>    // std::min
#include "shipwar.hpp"



int main(){
	Shipwar *game = new Shipwar(8,7,4,3,1);
	game->fill_the_map();
	std::cout << "this is the generated bord" << '\n';
       	// ths code is left here for the testing purposes, if the viewer would wish to have a look at what is going on behind the curtains.
	//game->print_the_sea();
       	int row;
       	int column;
	std::cout << "number of ships placed on the sea "<< '\n';
	std::cout << "small : " <<	game-> n_of_small_ships << '\n';
	std::cout << "medium : " << game-> n_of_medium_ships << '\n';
	std::cout << "big : " << game-> n_of_big_ships << '\n';
       	while (game->sum_of_all_squares !=0){
		do{
              		std::cout << "input the coordinates" << '\n';
               		std::cin >> row;
               		std::cin >> column;
		}while((std::min(row,column)<=0)||((std::min(row,column)>(game->board_height)*(game->board_length))));
               	game->shut(row-1, column-1);
       	}
        std::cout << "game is over. All ships are shut" << '\n';
        delete game;
	return 0;
}
