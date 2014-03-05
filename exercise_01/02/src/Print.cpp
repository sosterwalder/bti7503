/*
  File: Print.cpp
  Biel School of Engineering, Computer Science Division.
  Originally written by Roger Cattin (c) 2001

  History:
  Date     Who                          What
  Nov01    roger.cattin@hta-bi.bfh.ch   Created.
  Oct06    michael.maeder@bfh.ch        Modified
*/

#include <iostream>
#include "Board.h"
#include "Point.h"
#include "SPoint.h"


/*******************************************************************
// The function makes a right-angle triangle with sides of length 'dim'
// and the vertex with coordinates (x, y)
// Memory is allocated dynamically for each point of the triangle,
// the pointers to the points are stored in the array 'figure'. 
void makeTriangle( Point **figure, int dim, int x, int y )
{
    int next = 0;

    for( int i = 0; i < dim; ++i )
        for( int j = 0; j < dim - i; ++j )
        {
            // a new point with coordinates (x + j, y + i) is allocated
            figure[next] = new Point( x + j, y + i );
            ++next;
        }
}

// The function makes a square with of length 'dim'
// and the bottom left corner with coordinates (x, y)
// Memory is allocated dynamically for each point of the square,
// the pointers to the points are stored in the array 'figure'. 
void makeSquare( Point **figure, int dim, int x, int y )
{
    int next = 0;

    for( int i = 0; i < dim; ++i )
        for( int j = 0; j < dim; ++j )
        {
            // a new point with coordinates (x + j, y + i) is allocated
            figure[next] = new Point( x + j, y + i );
            ++next;
        }
} 
*////////////////////////////////////////////////////////////////////////

// The function draws the figure stored in the array 'figure' to 
// the board b. 
// If the coordinates are off the board, then the error message is
// displayed, and the program terminates.
void writeToBoard( Point **figure, Board &b )
{
    for( int i = 0; figure[i] != 0; ++i )
        // setting the point, checking coordinates are valid
        // the method copyToBoard is called for each of the points
        if( figure[i] -> copyToBoard(b) == false )
        {
            // if off the board, exit the program
            std::cout << "Point (" << figure[i] -> getX() << "," << figure[i] -> getY();
            std::cout << ") is off the board" << std::endl;
            exit(1);
        }
}

// The function moves a figure stored in array 'figure' by x_move on the 
// axis x and by y_move on the axis y. 
void moveFigure( Point** figure, int x_move, int y_move )
{
    for( int i = 0; figure[i] != 0; ++i )
        figure[i] -> move(x_move, y_move);
}

// When testing the class Spoint, remove the comments:
//*******************************************************************
void makeSymbTriangle( Point **figure, int dim, int x, int y, char s )
{
    int next = 0;

    for( int i = 0; i < dim; ++i )
        for( int j = 0; j < dim - i; ++j )
        {
            figure[next] = new SPoint (x + j, y + i, s);
            ++next;
        }
}

void makeSymbSquare( Point **figure, int dim, int x, int y, char s )
{
    int next = 0;

    for( int i = 0; i < dim; ++i )
        for( int j = 0; j < dim; ++j )
        {
            figure[next] = new SPoint (x + j, y + i, s);
            ++next;
        }
} 
//*////////////////////////////////////////////////////////////////////////


int main()
{
    // a new board
    Board b;

    // allocating two arrays of pointers to the class Point
    // for the two figures.
    // All the elements are initialized to zero (i.e. to  NULL).
    // We use the value 0 (NULL) to indicate the end of a figure,
    // therefore the size of the array equals the number of points in the
    // figure plus 1.
    Point *figure1[11] = {0};
    Point *figure2[17] = {0};

    //makeTriangle( figure1, 4, 7, 3 );
    //makeSquare( figure2, 4, 10, 12 );

    // For testing a symbol point call thse methods instead of
    // the ones above:
    makeSymbTriangle( figure1, 4, 7, 3, '$' );
    makeSymbSquare( figure2, 4, 10, 12, '&' );

    // draw the figures on the board
    writeToBoard( figure1, b );
    writeToBoard( figure2, b );

    // print the board to the screen
    b.print();

    // erase the old figures from the board
    b.eraseAll();

    // move the figures
    moveFigure( figure1, 5, 5 );
    moveFigure( figure2, -5, -5 );

    // draw the new figures on the board
    writeToBoard( figure1, b );
    writeToBoard( figure2, b );

    // print the board to the screen
    b.print();

    // deleting dynamic memory allocated for points
    for( int i = 0; figure1[i] != 0; ++i )
        delete figure1[i];

    for( int i = 0; figure2[i] != 0; ++i )
        delete figure2[i];

    std::cout << "Total Point-instances: " << Point::getInstanceCount() << std::endl;

    return 0;
} 
