
This is the README file of Shipwar project developed by
Olya Yeritspokhyan.

CONTENTS
        1. AUTHOR
        2. INTRODUCTION
        3. PREREQUISITES
        4. INSTALL
        5. DIRECTORY STRUCTURE
        6. USAGE
        7. DOCUMENTATION

1. AUTHOR
Olya Yeritspokhyan
Intern, Instigate CJSC

2. INTRODUCTION

Shipwar project  is a primitive implementation of Battleship game.
The project is done only in educational purposes, it provides better
understanding of development process of an application, the content of
documentation and usage of doxygen and makefile.
 
The application contains a grid representing the board (sea) from Battleship game.
The sea contains ships that are not seen by the user and need to be shut.
The game ends when all ships are shut.

The board consists of squares, each square has a coordinate. User should input
coordinates of the squares they want to shut. Small ship size is one square,
medium is two squares and the big ship is three consecutive squares.

The game is played using Terminal and does not have a Graphical Interface.


3. PREREQUISITES
The following third party tools and libraries should be installed before the
compilation.

Tools:
g++
doxygen
git

Libraries:
c++ standard libraries


3) To install prerequisite tools execute the following commands.
On Ubuntu:
 > apt-get install git
 > apt-get install g++
 > apt-get install doxygen

	

5) Build the project
	make

6) Generate the project documentation
	make docs.

6) Run the game
	./bin/shipwar.exe

5. DIRECTORY STRUCTURE

src/            - the source files of the project
docs/           - documentation of the project (e.g. PRD, fspec, devspec)
Makefile        - makefile to build the project
config-file     - doxygen configuration for the documentation of the project

7. DOCUMENTATION
"make docs" command generates doxygen documentation.

Doxygen generates documentation from C/C++ code comments.

To see the generated documentation use ./docs/doxygen/html/index.html.

// vim:fo=croqt:cindent:expandtab:textwidth=80:tabstop=8:shiftwidth=8:
