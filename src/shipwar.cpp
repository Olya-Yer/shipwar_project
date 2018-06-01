/**
 * @file shipwar.cpp "src/shipwar.hpp"
 * @author Olya Yeritspokhyan
 * @date 24 May 2018
 * @brief File containing implementation of class constructors and methods defiled in shipwar.hpp "src/shipwar.hpp".
 */

#include <iostream>	//cout
#include <time.h>	//rand()
#include <typeinfo>     //for typeid
#include <cstdlib>
#include <stdlib.h> 
#include "assert.h"
#include "shipwar.hpp"
//using namespace std;


Shipwar::Shipwar ()
{
        board_height = 10;
        board_length = 10;
        n_of_small_ships = 6;
        n_of_medium_ships = 4;
        n_of_big_ships = 4;
        sum_of_all_squares = n_of_small_ships+n_of_medium_ships*2+n_of_big_ships*3;
        init();
}

Shipwar::Shipwar (int board_height1,int board_length1,int n_of_small_ships1,int n_of_medium_ships1, int n_of_big_ships1)
{
        board_height = board_height1;
        board_length = board_length1;
        n_of_small_ships = n_of_small_ships1;
        n_of_medium_ships = n_of_medium_ships1;
        n_of_big_ships = n_of_big_ships1;
        init();
}

Shipwar::~Shipwar ()
{
        free(current_sea);
}

void Shipwar::init ()
{
        current_sea = new int[board_height*board_length]{0};
        if(NULL == current_sea) {
                std::abort();
        }
        sum_of_all_squares = n_of_small_ships+n_of_medium_ships*2+n_of_big_ships*3;
        srand( time( NULL ) ); 
}

bool Shipwar::fill_the_square(int row, int col)
{
        assert(col>=0);
        assert(row>=0);
        assert(row<board_height);
        assert(col < board_length);
        assert(current_sea);
        if(current_sea[row*board_length+col]!=1) {
                current_sea[row*board_length+col]=1;
                return 1;
        }
        else {
                return 0;
        }
}

bool Shipwar::is_square_free(int row, int col)
{
        assert(col>=0);
        assert(row>=0);
        assert(row<board_height);
        assert(col < board_length);
        assert(current_sea);
        return current_sea[row*board_length+col]!=1;
}

bool Shipwar::is_positive(int row, int col)
{       
        assert(col>=0);
        assert(row>=0);
        assert(row<board_height);
        assert(col < board_length);
        return (row*board_length+col)>=0; 
}

bool Shipwar::is_within_borders(int row, int col)
{      
        assert(col>=0);
        assert(row>=0);
        assert(row<board_height);
        assert(col < board_length);
        return (row*board_length+col) <= (board_height*board_length); 
}

bool Shipwar::is_square_valid(int row, int col)
{
        assert(col>=0);
        assert(row>=0);
        assert(row<board_height);
        assert(col < board_length);
        return (is_positive(row,col)&&is_within_borders(row,col));
}

bool Shipwar::check_side(int row, int col)
{
        assert(col>=0);
        assert(row>=0);
        assert(row<board_height);
        assert(col < board_length);
        return (is_square_valid(row, col)&&is_square_free(row, col));
}

bool Shipwar:: not_upper_corner(int row, int col)
{
        assert(col>=0);
        assert(row>=0);
        assert(row<board_height);
        assert(col < board_length);
        return ((row >0)&&(col >0));
}

bool Shipwar:: not_lower_corner(int row, int col)
{
        assert(col>=0);
        assert(row>=0);
        assert(row<board_height);
        assert(col < board_length);
        return ((row < (board_height-1))&&(col< (board_length-1)));
}

bool Shipwar::is_not_on_corner(int row, int col)
{       
        assert(col>=0);
        assert(row>=0);
        assert(row<board_height);
        assert(col < board_length);
        return (not_upper_corner(row,col)&&not_lower_corner(row,col));
}

bool Shipwar::check_all_sides(int row, int col)
{
        assert(col>=0);
        assert(row>=0);
        assert(row<board_height);
        assert(col < board_length);
        if(check_side(row-1,col)&&check_side(row+1,col)) {
                return check_side(row,col-1)&&check_side(row,col+1);
        }
}

bool Shipwar:: is_on_upper_left(int row, int col)
{  
        assert(col>=0);
        assert(row>=0);
        assert(row<board_height);
        assert(col < board_length);
        return ((0 == row)&&(0 == col)); 
}

bool Shipwar:: check_upper_left(int row, int col)
{
        assert(col>=0);
        assert(row>=0);
        assert(row<board_height);
        assert(col < board_length);
        return (check_side(row+1,col)&&check_side(row,col+1)); 
}

bool Shipwar:: is_on_upper_right(int row, int col)
{
        assert(col>=0);
        assert(row>=0);
        assert(row<board_height);
        assert(col < board_length);
        return ((0 == row)&&(board_length-1 == col));
}

bool Shipwar:: check_upper_right(int row, int col)
{
        assert(col>=0);
        assert(row>=0);
        assert(row<board_height);
        assert(col < board_length);
        return (check_side(row+1,col)&&check_side(row,col-1)); 
}

bool Shipwar:: is_on_lower_left(int row, int col)
{
        assert(col>=0);
        assert(row>=0);
        assert(row<board_height);
        assert(col < board_length);
        return ((board_height-1 == row)&&(0 == col)); 
}

bool Shipwar:: check_lower_left(int row, int col)
{
        assert(col>=0);
        assert(row>=0);
        assert(row<board_height);
        assert(col < board_length);
        return check_side(row-1,col)&&check_side(row,col+1);
}

bool Shipwar:: is_on_lower_right(int row, int col)
{
        assert(col>=0);
        assert(row>=0);
        assert(row<board_height);
        assert(col < board_length);
        return  ((board_height -1  == row)&&(board_length-1 == col)); 
}

bool Shipwar:: check_lower_right(int row, int col)
{
        assert(col>=0);
        assert(row>=0);
        assert(row<board_height);
        assert(col < board_length);
        return (check_side(row-1,col)&&check_side(row,col-1));
}

bool Shipwar::is_on_silling(int row, int col)
{
        assert(col>=0);
        assert(row>=0);
        assert(row<board_height);
        assert(col < board_length);
        return ((0== row)&&(col > 0)&&(col < board_length -1));
}

bool Shipwar::check_silling(int row, int col)
{
        assert(col>=0);
        assert(row>=0);
        assert(row<board_height);
        assert(col < board_length);
        return (check_side(row+1,col)&&check_side(row,col-1)&&check_side(row,col+1));
}

bool Shipwar::is_on_floor(int row, int col)
{
        assert(col>=0);
        assert(row>=0);
        assert(row<board_height);
        assert(col < board_length);
        return ((board_height -1 == row)&&(col > 0 )&&(col < board_length -1));
}

bool Shipwar::check_floor(int row, int col)
{
        assert(col>=0);
        assert(row>=0);
        assert(row<board_height);
        assert(col < board_length);
        return (check_side(row-1,col)&&check_side(row,col-1)&&check_side(row,col+1));
}

bool Shipwar::check_sides( int row, int col)
{
        assert(col>=0);
        assert(row>=0);
        assert(row<board_height);
        assert(col < board_length);
        if (is_not_on_corner( row, col) && check_all_sides(row,col)) {
                return 1;
        }
        else if (is_on_upper_left(row,col)&&check_upper_left(row,col)) {
                return 1;
        }
        else if (is_on_upper_right(row,col) && check_upper_right(row,col)) {
                return 1;
        }
        else if (is_on_silling(row,col) && check_silling(row,col) ) {
                return 1;
        }
        else if (is_on_lower_left(row, col) && check_lower_left( row, col)) {
                return 1;
        }
        else if (is_on_lower_right( row, col)&& check_lower_right( row, col)) {
                return 1;
        }
        else if (is_on_floor(row,col) && check_floor(row,col) ) {
                return 1;
        }
        return 0;
}

void Shipwar::fill_small_ships()
{
        int n = n_of_small_ships;
        assert(current_sea);
        while (n!=0) {
                int row = rand()%10;
                int col = rand()%10;
                if (check_sides(row,col)) {
                        if(fill_the_square(row,col)) {
                                n -= 1;
                        }
                }
        }
}

int Shipwar::get_row(int row)
{       
        assert(row>=0);
        assert(row<board_height);
        int newRow=0;
        if (row< (board_height-1)) {
                newRow = row+1 ;
        } else {
                newRow = row-1;
        }
        return newRow;
}

int Shipwar::get_col(int col)
{
        assert(col>=0);
        assert(col < board_length);
        int newCol=0;
        if (col< (board_length-1)) {
                newCol = col+1 ;
        } else {
                newCol = col-1;
        }
        return newCol;
}
void Shipwar::fill_medium_ships()
{
        int n = n_of_medium_ships;
        while (n!=0) {
                bool direction= rand()%2;
                int row = rand()%10;
                int col = rand()%10;
                int row2 =0;
                int col2 =0;
                if (direction) {
                        row2 = get_row(row);
                        col2 = col;
                } else {
                        row2 = row;
                        col2 = get_col(col);
                }
                if(is_square_free(row,col)&&check_sides(row,col)&&check_sides(row2,col2)) {
                        fill_the_square(row,col);
                        fill_the_square(row2,col2);
                        n--;
                }
        }
}
void Shipwar::fill_big_ships()
{
        int n =n_of_big_ships;
        while (n!=0) {
                bool direction= rand()%2;
                int row = rand()%board_height;
                int col = rand()%board_length;
                int row2 =0;
                int col2 =0;
                int row3 =0;
                int col3 =0;
                if (direction) {
                        row2 = get_row(row);
                        row3 = get_row(row2);
                        if(row3 == row) {
                                row3 = row-1;
                        }
                        col2 = col;
                        col3 = col;
                } else {
                        row2 = row;
                        row3 = row;
                        col2 = get_col(col);
                        col3 = get_col(col2);
                        if(col3 == col) {
                                col3 = col-1;
                        }
                }
                if(is_square_free(row,col)&&check_sides(row,col)&&check_sides(row2,col2)&&check_sides(row3,col3)) {
                        fill_the_square(row,col);
                        fill_the_square(row2,col2);
                        fill_the_square(row3,col3);
                        n--;
                }
        }
}

void Shipwar::fill_the_map()
{
        fill_small_ships();
        fill_medium_ships();
        fill_big_ships();
}

void Shipwar::set_checked(int row, int col)
{       
        assert(col>=0);
        assert(row>=0);
        assert(row<board_height);
        assert(col < board_length);
        assert(current_sea);
        current_sea[row*board_length+col]=2;
}

bool Shipwar::is_checked(int row, int col)
{       
        assert(col>=0);
        assert(row>=0);
        assert(row<board_height);
        assert(col < board_length);
        assert(current_sea);
        return 2 == current_sea[row*board_length+col];
}

void Shipwar::shoot(int row, int col)
{       
        assert(col>=0);
        assert(row>=0);
        assert(row<board_height);
        assert(col < board_length);
        if(is_checked(row,col)) {
                std::cout << "you have already tried shooting here" << '\n';
        } else if(is_square_free(row,col)) {
                set_checked(row,col);
                std::cout << "miss" << '\n';
        } else if(!is_square_free(row,col)) {
                set_checked(row,col);
                std::cout << "you hit a ship" << '\n';
                int sum_of_all_squares = this->sum_of_all_squares;
                this->sum_of_all_squares = sum_of_all_squares -1;
                if (!check_sides(row,col)) {
                        std::cout << "the ship is still alive" << '\n';
                } else {
                        std::cout << "ship is killed" << '\n';
                }
        }

}

void Shipwar::print_the_sea()
{
        assert(current_sea);
        for(int i = 0; i < board_height; i++) {
                for(int j = 0; j <board_length ; j++) {
                        std::cout << current_sea[i*board_length+j] << ' ';
                }
                std::cout << '\n';
        }
}

void Shipwar::play()
{
        fill_the_map();
        // ths code is left here for the testing purposes, if the viewer would wish to have a look at what is going on behind the curtains.
        //std::cout << "this is the generated bord" << '\n';
        //game->print_the_sea();
        int row=100;
        int column=100;
        std::cout << "number of ships placed on the sea "<< '\n';
        std::cout << "small : " << n_of_small_ships << '\n';
        std::cout << "medium : " <<  n_of_medium_ships << '\n';
        std::cout << "big : " << n_of_big_ships << '\n';
        while(sum_of_all_squares !=0) {
                do {
                        std::cout << "input the coordinates" << '\n';
                        std::cin >> row;
                        std::cin >> column;
                        assert(row);
                        assert(column);
                } while((row<=0)||(column<=0)||((row>board_height)||(column>board_length)));
                shoot(row-1, column-1);
        }
}
// vim:et:tabstop=8:shiftwidth=8:cindent:fo=croq:textwidth=80:
