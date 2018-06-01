/****************************************************************************
 *    Copyright (C) 2018 by Olya Yeritspokhyan                              *
 *                                                                          *
 *    This file is part of Shipwar game.                                    *
 *                                                                          *
 *   Shipwar is a game that,in this implementation is played with the       *
 *   computer using console.                                                *
 *                                                                          *
 *   Shipwar was made in educational purposes only.                         *
 *                                                                          *
 ****************************************************************************/

/**
 * @headfile shipwar.hpp "src/shipwar.hpp"
 * @author Olya Yeritspokhyan
 * @date 24 May 2018
 * @brief File containing header information of Shipwar game.
 */


/**
 * @class Shipwar shipwar.h "src/shipwar.h"
 * @brief This class contains all constructors and  methods.
 * In this class we construct a grid(sea) of size 10x10, fill it with three types of ships
 */
class Shipwar
{
        // TODO change the names of privet class members to m_name
        public:
                // The game board. This is an one dimensional array that is treated as a matrix(grig)
                int *current_sea;
                //height of the matrix that is sea(i.e. number of rows)
                int board_height;
                //width of the matrix that is sea(i.e. number of columns)
                int board_length;
                // Number of small ships that are placed on the board. Small ship is a square with value 1 
                int n_of_small_ships;
                /** Number of medium ships that are placed on the board.
                 * Medium ship is a sequence of two squares with value 1.
                 * Medium ship can be horizontal or vertical
                 */
                int n_of_medium_ships;
                /** Number of big ships that are placed on the board.
                 * Big ship is a sequence of three squares with value 1.
                 * Big ship can be horizontal or vertical
                 */
                int n_of_big_ships;
                /**sum of all squares that need to be shooted.
                 * (i.e.all ones in the matrix filled with zeros)
                 */
                int sum_of_all_squares;
                /**
                 * @brief class default constructor
                 * @details by default the game is played on 10x10 board
                 * with number of small,medium and big ships 6,4,4 respectively
                 */
                Shipwar();
                /**
                 * @brief class destructor
                 */
                ~Shipwar();
                /**
                 * @brief class constructor
                 * @details by default the game is played on 10x10 board
                 * with number of small,medium and big ships 6,4,4 respectively.
                 */
                Shipwar(int board_height,int board_length,int n_of_small_ships,int n_of_medium_ships, int n_of_big_ships);
                /**
                 * @brief A method to shoot the ship
                 * @param[in] row - x coordinate of the square
                 * @param[in] col - y coordinate of the square
                 * This method tries to shoot the ship and tells if shooting was successful,
                 * if yes , is the ship just damaged(still alive) or it was killed or
                 * was the square already shooted.
                 */
                void shoot(int row, int col);
                /**
                 * @brief A method to create the board in constructors
                 */
                void init();
                /**
                 * @brief A method to start the game
                 * This method asks the user for an imput coordinates and shoots the square
                 * until all squares with ships are shooted.
                 */
                void play();
                /**
                 * @brief sets the square already shooted
                 */
                void set_checked(int row, int col);
                /**
                 * @brief checks if the square index is more than 0
                 * @param[in] row - x coordinate of the square
                 * @param[in] col - y coordinate of the square
                 */
                bool is_positive(int row, int col);
                bool is_within_borders(int row, int col);
                bool not_upper_corner(int row, int col);
                bool not_lower_corner(int row, int col);
                /**
                 * @brief Marks the square as already shoot
                 * @param[in] row - x coordinate of the square
                 * @param[in] col - y coordinate of the square
                 * @return bool - true, if the square was previously shooted , false if not.
                 * @details This function sets the valuer of the square that it wants to mark to 2.
                 */
                bool is_checked(int row, int col);

                /**
                 * @brief constructs the ship
                 * @param[in] row - x coordinate of the square
                 * @param[in] col - y coordinate of the square
                 * @return bool - true, if the square was successfully set to 1, false if it already was set to 1.
                 * @details This function sets the value of the square to 1 if it was 0
                 */
                bool fill_the_square(int Row, int Col);

                /**
                 * @brief Fills the map with small ships
                 * @details changes square value in the matrix from 0 to 1. Coordinates are picked randomly.
                 */
                void fill_small_ships();
                // @brief checks if the square is not one of the corner cases.
                bool is_not_on_corner(int row,int col);
                /**
                 * @brief Fills the map with medium ships
                 * @details for each medium ship picks random coordinates for start of the ship,
                 * randomly decides if the ship will be horizontal(i.e. two consecutive squares in the same row will be set to 1)
                 * or vertical (i.e. two consecutive squares in the same column will be set to 1),
                 * puts the second part of the ship in the adjacent square.
                 */
                void fill_medium_ships();
                /**
                 * @brief Fills the map with big ships
                 * @details for each big ship picks random coordinates row and column,
                 * randomly decides if the ship will be horizontal(i.e. three consecutive squares in the same row will be set to 1)
                 * or vertical (i.e. three consecutive squares in the same column will be set to 1)
                 * puts the second and third part of the ship in the adjacent squares.
                 */
                void fill_big_ships();

                /**
                 * @brief Checks if there is no ship on the square
                 * @param[in] row - x coordinate of the square
                 * @param[in] col - y coordinate of the square
                 * @return bool - true, if the square is free, false otherwise.
                 */
                bool is_square_free(int row,int col);

                /**
                 * @brief Checks if the coordinates that were inputed are valid
                 * @param[in] row - x coordinate of the square
                 * @param[in] col - y coordinate of the square
                 * @return bool - true, if the coordinates are valid;
                 */
                bool is_square_valid(int row,int col);
                /**
                 * @brief Checks if the square is valid and free
                 * @param[in] row - x coordinate of the square
                 * @param[in] col - y coordinate of the square
                 * @return bool - true, if the square is in the boundaries of the matrix and is free.
                 */
                bool check_side(int row,int col);

                /**
                 * @brief Checks there are no ships in adjacent squares
                 * @param[in] row - x coordinate of the square
                 * @param[in] col - y coordinate of the square
                 * @return bool - true, if there are no ships adjacent to this square
                 */
                bool check_sides(int row,int col);

                /**
                 * @brief gives row of the square that will be filled next
                 * @param[in] row - x  coordinate of a square
                 * @return bool - true, if there are no ships adjacent to this square
                 */
                int get_row(int row);
                /**
                 * @brief gives col of the square that will be filled next
                 * @param[in] col - y coordinate of a square
                 * @return bool - true, if there are no ships adjacent to this square
                 */
                int get_col(int col);
                /**
                 *@brief puts all ships on the board
                 *@details This function calls fill_small_ships(), fill_medium_ships(), fill_big_ships()
                 */
                void fill_the_map();

                /**
                 *@brief prints the whole matrix for testing purposes
                 */
                void print_the_sea();

                //functions used in check_sides(); 

                bool check_all_sides(int row, int col);

                bool is_on_upper_left(int row,int col);

                bool check_upper_left(int row,int col);

                bool is_on_upper_right(int row, int col);

                bool check_upper_right(int row,int col);

                bool is_on_lower_left(int row,int col);

                bool check_lower_left(int row,int col);

                bool is_on_lower_right(int row, int col);

                bool check_lower_right(int row,int col);

                bool is_on_silling(int row,int col);

                bool check_silling(int row,int col);

                bool is_on_floor(int row,int col);

                bool check_floor(int row,int col);


};
// vim:et:tabstop=8:shiftwidth=8:cindent:fo=croq:textwidth=80:
