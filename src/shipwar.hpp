/****************************************************************************
 *    Copyright (C) 2018 by Olya Yeritspokhyan                              *
 *                                                                          *
 *    his file is part of Shipwar game.                                     *
 *                                                                          *
 *   Shipwar is a game that,in this implementation is played with the       *
 *   computer using console.                                                *
 *                                                                          *
 *   Shipwar was made in educational purposes only.                         *
 *                                                                          *
 ****************************************************************************/

/**
 * @heardfile shipwar.hpp "src/shipwar.hpp"
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
  // TODO change the names of privet class member to m_name
private:
  // The game board. This is an one dimentional array that is treated as a matrix(grig)
  int *sea;
  //height of the matrix that is sea(i.e. number of rows)
public:
  int board_height;
  //width of the matrix that is sea(i.e. number of columns)
  int board_length;
  // Number of small ships that are plased on the board. Small ship is a square with value 1 
  int n_of_small_ships;
  /** Number of medium ships that are plased on the board.
  * Medium ship is a sequance of two squares with value 1.
  * Medium ship can be hurizontal or vertical
  */
  int n_of_medium_ships;
  /** Number of big ships that are plased on the board.
  * Big ship is a sequance of three squares with value 1.
  * Big ship can be hurizontal or vertical
  */
  int n_of_big_ships;
  /**sum of all squares that need to be shut.
  * (i.e.all ones in the matrix filled with zeros)
  */
  int sum_of_all_squares;
  /**
   * @brief class default constructor
   * @details by default the game is played on 10x10 board
   * with number of small,medium and big ships 6,4,4 respectively
   */
  Shipwar();
  ~Shipwar(){};
  // TODO write brief
  Shipwar(int board_height,int board_length,int n_of_small_ships,int n_of_medium_ships, int n_of_big_ships);
  /**
   * @brief A method to shut the ship
   * @param[in] row - x coordinate of the square
   * @param[in] col - y coordinate of the square
   * This method tries to shut the ship and tells if shutting was successful,
   * if yes , is the ship just damaged(still alive) or it was killed or
   * was the square already shut
   */
  void shut(int row, int col);

  /**
   * @brief A method to shut the ship
   * @param[in] row - x coordinate of the square
   * @param[in] col - y coordinate of the square
   * This method tries to shut the ship and tells if shutting was successful,
   * if successful,it also tells if the ship is just damaged(still alive) or it was killed or
   * was the square already shut.
   */
  void set_checked(int row, int col);
  /**
   * @brief Marks the square as already shut
   * @param[in] row - x coordinate of the square
   * @param[in] col - y coordinate of the square
   * @return bool - true, if the square was previously shut , false if not.
   * @details This function sets the valure of the square that it wants to mark to 2.
   */
  bool checked(int row, int col);

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
  // TODO: write brief
  bool is_not_on_corner(int row,int col);
  /**
   * @brief Fills the map with medium ships
   * @details for each medium ship picks random coordinates for start of the ship,
   * randomly decides if the ship will be horizontal(i.e. two consequtive squares in the same row will be set to 1)
   * or vertical (i.e. two consequtive squares in the same column will be set to 1),
   * puts the second part of the ship in the adjacent square.
   */
  void fill_medium_ships();
  /**
   * @brief Fills the map with big ships
   * @details for each big ship picks random coordinates row and column,
   * randomly decides if the ship will be horizontal(i.e. three consequtive squares in the same row will be set to 1)
   * or vertical (i.e. three consequtive squares in the same column will be set to 1)
   * puts the second and third part of the ship in the adjacent squares.
   */
  void fill_big_ships();

    /**
     * @brief Checks if there is no ship on the square
     * @param[in] row - x coordinate of the square
     * @param[in] col - y coordinate of the square
     * @return bool - true, if the square is free, false otherwise.
     */
  bool square_is_free(int row,int col);

  /**
   * @brief Checks if the coordinates that were inputed are valid
   * @param[in] row - x coordinate of the square
   * @param[in] col - y coordinate of the square
   * @return bool - true, if the coordinates are valid;
   */
  bool square_is_valide(int row,int col);
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
   * @return bool - true, if there are no ships adjacent to this sqaure
   */
  bool check_sides(int row,int col);

  /**
   * @brief gives row of the square that will be filled next
   * @param[in] row - x  coordinate of a square
   * @return bool - true, if there are no ships adjacent to this sqaure
   */
  int get_row(int row);
  /**
   * @brief gives col of the square that will be filled next
   * @param[in] col - y coordinate of a square
   * @return bool - true, if there are no ships adjacent to this sqaure
   */
  int get_col(int col);
  /**
   *@brief puts all ships on the board
   *@details This function calls fillSmallShips(), fill_medium_ships(), fill_big_ships()
   */
  void fill_the_map();

  /**
   *@brief prints the whole matrix for testing purposes
   */
  void print_the_sea();

};
