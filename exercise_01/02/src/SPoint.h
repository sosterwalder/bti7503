#ifndef __SPOINT_H__
#define __SPOINT_H__

#include <cstdio>
#include <iostream>
#include "Point.h"
#include "Board.h"

class SPoint : public Point
{
public:
    SPoint(int x, int y, char symbol);
    bool copyToBoard(Board& b);

private:
    char symb;
};

#endif
