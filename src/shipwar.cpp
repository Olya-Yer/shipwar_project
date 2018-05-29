 /**
  * @file shipwar.cpp "src/shipwar.hpp"
  * @author Olya Yeritspokhyan
  * @date 24 May 2018
  * @brief File containing implementation of class cunstractors and methods defiled in shipwar.hpp "src/shipwar.hpp".
  */

#include <iostream>	//cout
#include <time.h>	//rand()
#include "assert.h"
#include "shipwar.hpp"
using namespace std;


Shipwar::Shipwar()
{
        board_height = 10;
        board_length = 10;
        sea = new int[board_height*board_length]{0};
        if(NULL == sea) {
                std::abort();
        }
	n_of_small_ships = 6;
        n_of_medium_ships = 4;
        n_of_big_ships = 4;
        sum_of_all_squares = n_of_small_ships+n_of_medium_ships*2+n_of_big_ships*3;
        srand( time( NULL ) );
}
Shipwar::Shipwar(int board_height1,int board_length1,int n_of_small_ships1,int n_of_medium_ships1, int n_of_big_ships1)
{
        board_height = board_height1;
        board_length = board_length1;
        sea = new int[board_height*board_length]{0};
        if(NULL == sea) {
                std::abort();
        }
        n_of_small_ships = n_of_small_ships1;
        n_of_medium_ships = n_of_medium_ships1;
        n_of_big_ships = n_of_big_ships1;
        sum_of_all_squares = n_of_small_ships+n_of_medium_ships*2+n_of_big_ships*3;
        srand( time( NULL ) );
}

bool Shipwar::fill_the_square(int row, int col)
{
        int *current_sea = this->sea;
        assert(current_sea);
        if(current_sea[row*board_length+col]!=1) {
                current_sea[row*board_length+col]=1;
                return 1;
        }
        else {
                return 0;
        }
}
bool Shipwar::square_is_free(int row,int col)
{
        int *current_sea = this->sea;
        assert(current_sea);
        return current_sea[row*board_length+col]!=1;
}
bool Shipwar::square_is_valide(int row,int col)
{
        return ( (row*board_length+col)>=0) && ( (row*board_length+col) <= (board_height*board_length) );
}
bool Shipwar::check_side(int row,int col)
{
        return (square_is_valide(row, col)&&square_is_free(row, col));
}
bool Shipwar::is_not_on_corner(int row,int col)
{
        return (row > 0) && (col > 0) && ( row< (board_height-1)) && ( col< (board_length-1));
}

bool Shipwar::check_sides(const int row,const int col)
{
        if(is_not_on_corner( row, col)) {
                if( check_side(row-1,col) && check_side(row+1,col) && check_side(row,col-1)&&check_side(row,col+1)) {
                        return 1;
                }
        }
        else if(0 == row) {
                if(0== col) {
                        if(check_side(row+1,col)&&check_side(row,col+1)) {
                                return 1;}
                }
                else if(board_length-1== col) {
                        if(check_side(row+1,col)&&check_side(row,col-1)) {
                                return 1;}
                }
                else {
                        if(check_side(row+1,col)&&check_side(row,col-1)&&check_side(row,col+1)) {
                                return 1;}
                }
        }
        else if((board_height-1) == row) {
                if(0== col) {
                        if(check_side(row-1,col)&&check_side(row,col+1)) {
                                return 1;}
                }
                else if((board_length-1)== col) {
                        if(check_side(row-1,col)&&check_side(row,col-1)) {
                                return 1;}
                }
                else {
                        if(check_side(row-1,col)&&check_side(row,col-1)&&check_side(row,col+1)) {
                                return 1;}
                }
        }
        else if(0 == col) {
                if(check_side(row-1,col)&&check_side(row,row+1)&&check_side(row,col+1)){
                        return 1;}
        }
        else if((board_length-1) == col) {
                if(check_side(row-1,col)&&check_side(row,row+1)&&check_side(row,col-1)) {
                        return 1;}
        }
        return 0;
}

void Shipwar::fill_small_ships()
{
        int n = n_of_small_ships;
        int *current_sea = this->sea;
        assert(current_sea);
        while (n!=0){
                int row = rand()%10;
                int col = rand()%10;
                if (check_sides(row,col)){
                        if(fill_the_square(row,col)){
                                n -= 1;
                        }
                }
        }
}

int Shipwar::get_row(int row)
{
        int newRow;
        if (row< (board_height-1)) {
                newRow = row+1 ;
        }
        else {
                newRow = row-1;
        }
        return newRow;
}
int Shipwar::get_col(int col)
{
        int newCol;
        if (col< (board_length-1)) {
                newCol = col+1 ;
        }
        else {
                newCol = col-1;
        }
        return newCol;
}
void Shipwar::fill_medium_ships()
{
        int n = n_of_medium_ships;
        while (n!=0){
                bool direction= rand()%2;
                int row = rand()%10;
                int col = rand()%10;
                int row2 ;
                int col2 ;
                if (direction){
                        row2 = get_row(row);
                        col2 = col;
                }
                else{
                        row2 = row;
                        col2 = get_col(col);
                }
                if(square_is_free(row,col)&&check_sides(row,col)&&check_sides(row2,col2)){
                        fill_the_square(row,col);
                        fill_the_square(row2,col2);
                        n--;
                }
        }
}
void Shipwar::fill_big_ships()
{
        int n =n_of_big_ships;
        // std::cout << "n_of_big_ships"<<n_of_big_ships << '\n';
        while (n!=0){
          // std::cout << "creating a ship" << '\n';
                bool direction= rand()%2;
                int row = rand()%board_height;
                int col = rand()%board_length;
                int row2 ;
                int col2 ;
                int row3 ;
                int col3 ;
                if (direction){
                        row2 = get_row(row);
                        row3 = get_row(row2);
                        if(row3 == row){
                                row3 = row-1;
                        }
                        col2 = col;
                        col3 = col;
                }
                else{
                        row2 = row;
                        row3 = row;
                        col2 = get_col(col);
                        col3 = get_col(col2);
                        if(col3 == col){
                                col3 = col-1;
                        }
                }
                if(square_is_free(row,col)&&check_sides(row,col)&&check_sides(row2,col2)&&check_sides(row3,col3)){
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
        int *current_sea = this->sea;
        assert(current_sea);
        current_sea[row*board_length+col]=2;
}
bool Shipwar::checked(int row, int col)
{
        int *current_sea = this->sea;
        assert(current_sea);
        return current_sea[row*board_length+col]==2;
}
void Shipwar::shut(int row, int col)
{
        if(square_is_free(row,col)){
                set_checked(row,col);
                std::cout << "miss" << '\n';
        }
        else if(checked(row,col)){
                std::cout << "you have already tried shuting here" << '\n';
        }
        else if(!square_is_free(row,col)){
                set_checked(row,col);
                std::cout << "you hit a ship" << '\n';
                int sum_of_all_squares = this->sum_of_all_squares;
                this->sum_of_all_squares = sum_of_all_squares -1;
                if (!check_sides(row,col)){
                        std::cout << "the ship is still alive" << '\n';
                }
                else{
                        std::cout << "ship is killed" << '\n';
                }
        }

}
void Shipwar::print_the_sea()
{
        int *current_sea = this->sea;
        assert(current_sea);
        for (int i = 0; i < board_height; i++){
                for (int j = 0; j <board_length ; j++){
                        std::cout << current_sea[i*board_length+j] << ' ';
                }
                std::cout << '\n';
        }
}
