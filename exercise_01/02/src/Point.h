#ifndef Point_H
#define Point_H
/*
  File: Point.h
  Biel School of Engineering, Computer Science Division.
  Originally written by Roger Cattin (c) 2001

  History:
  Date     Who                          What
  Nov01    roger.cattin@hta-bi.bfh.ch   Created.
  Oct06    michael.maeder@bfh.ch        Modified
*/

#include "Board.h"

class Point
{
public:
    Point( int x_coord, int y_coord );
    int getX( void );
    int getY( void );
    void move ( int x_move, int y_move );
    virtual bool copyToBoard ( Board & );
    static std::size_t getInstanceCount() { return Point::instanceCount_; }

private:
    // coordinates of the point
    int x;
    int y;

    // Number of instances
    static std::size_t instanceCount_;
};

# endif
