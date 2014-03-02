/*
  File: Board.cpp
  Biel School of Engineering, Computer Science Division.
  Originally written by Roger Cattin (c) 2001

  History:
  Date     Who                          What
  Nov01    roger.cattin@hta-bi.bfh.ch   Created.
  Oct06    michael.maeder@bfh.ch        Modified
*/

#include <cstdio>
#include <iostream>
#include "Board.h"

#define EmptyField '.'

// the constructor initializes the board to all whitespaces
Board::Board()
{
    int i, j;

    for (i = 0; i < 20; ++i)
        for (j = 0; j < 20; ++j)
        storage[i][j] = EmptyField;
}

// the method sets the point with coordinates (x,y) to the symbol symb
// returns 'false' if the coordinates are off the board, 
// returns 'true' otherwise
bool Board::write( int x, int y, char symb )
{
    // checking that coordinates are within the board
    if (x < 0 || x > 19 || y < 0 || y > 19)
        return false;
  
    // setting the point to the symbol
    storage[x][y] = symb;
    return true;
}

// the method erases the point with coordinates (x, y) by changing its 
// symbol to a space
bool Board::erase( int x, int y )
{
    // checking that coordinates are within the board
    if (x < 0 || x > 19 || y < 0 || y > 19)
        return false;
  
    // erasing the point
    storage[x][y] = EmptyField;
    return true;
}

// the method erases all points on the board
void Board::eraseAll( void )
{
    int i, j;

    for (i = 0; i < 20; ++i)
    for (j = 0; j < 20; ++j)
        storage[i][j] = EmptyField;
}

// the method prints the board to the screen
void Board::print( void )
{
    int i, j;

    std::cout << "=======================================" << std::endl;

    for (i = 0; i < 20; ++i) {
        for (j = 0; j < 20; ++j)
        std::cout << storage[i][j];
        std::cout << std::endl;
    }

    std::cout << "=======================================" << std::endl;
}
