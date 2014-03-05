#include "SPoint.h"

SPoint::SPoint(int x, int y, char symbol) : Point(x, y)
{
    this->symb = symbol;
}

bool SPoint::copyToBoard(Board& b)
{
    return b.write(getX(), getY(), symb);
}
