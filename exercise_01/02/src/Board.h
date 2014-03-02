#ifndef Board_H
#define Board_H
/*
  File: Board.h
  Biel School of Engineering, Computer Science Division.
  Originally written by Roger Cattin (c) 2001

  History:
  Date     Who                          What
  Nov01    roger.cattin@hta-bi.bfh.ch   Created.
  Oct06    michael.maeder@bfh.ch        Modified
*/

class Board
{
public:
    Board();
    
    void print( void );
    bool write( int x, int y, char symb );
    bool erase( int x, int y );
    void eraseAll( void );

    // the board has fixed size 20 by 20
private:
    char storage[20][20];
};

#endif
