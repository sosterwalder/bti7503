/* -*- coding: UTF-8 -*-
 * 
 * vim: autoindent expandtab tabstop=4 sw=4 sts=4 filetype=cpp
 * 
 * The MIT License (MIT)
 * 
 * Copyright (c) 2014 Sven Osterwalder
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 * 
 * Standards according to http://google-styleguide.googlecode.com/svn/trunk/cppguide.xml
 * 
 * SPoint.cpp

  * Class implementation of an (ASCII-) point defined/displayed
  * by a given symbol. The class inherits from the base class
  * Point and provides therefore its public interfaces.
  */

#include "SPoint.h"

/// Constructor
SPoint::SPoint(int x, int y, char symbol) : Point(x, y)
{
    this->symb = symbol;
}

/*
 * Writes the currently set symbol at
 * the currently set x and y coordinates
 * to the given board
 *
 * @param   b   Board&  Reference to a board object
 * @return  boolean Result
 */
bool SPoint::copyToBoard(Board& b)
{
    return b.write(getX(), getY(), symb);
}
