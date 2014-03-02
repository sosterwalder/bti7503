/*
  File: Point.cpp
  Biel School of Engineering, Computer Science Division.
  Originally written by Roger Cattin (c) 2001

  History:
  Date     Who                          What
  Nov01    roger.cattin@hta-bi.bfh.ch   Created.
  Oct06    michael.maeder@bfh.ch        Modified
*/

#include <cstdio>
#include "Point.h"


// the constructor initializes the coordinates of the point
Point::Point( int x_coord, int y_coord )
{
    x = x_coord;
    y = y_coord;
}

// return the value of x coordinate
int Point::getX( void )
{
    return x;
}
  
// return the value of y coordinate
int Point::getY( void )
{
    return y;
}
  
// move the point by x_move on the x axis and by y_move on the y axis
void Point::move( int x_move, int y_move )
{
    x = x + x_move;
    y = y + y_move;
}

// Call the method 'write' of the board b
// the method returns 'true' if the write was successful and 'false' 
// otherwise (for instance, when the coordinates were off the board).
// The boolean value is passed to the calling function. 
// The third argument of the method 'write' is the symbol that will be used 
// to draw the point. The default symbol '*' is passed to the method.   
bool Point::copyToBoard( Board &b )
{
   return b.write(x, y, '*');
}
