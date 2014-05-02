/*
  File: Queue.h
  Biel School of Engineering, Computer Science Division.
  Originally written by Pierre Fierz (c) 2008

  History:
  Date       Who                         What
  Nov2408    pierre.fierz@bfh.ch         Created.

*/

#ifndef QUEUE_H_
#define QUEUE_H_

#include <stack>

template <class T>
class Queue {
public:
  Queue() {}
  Queue( const Queue& q );
  ~Queue() {}

  void enqueue( const T& e )
  {
    this->s1.push(e);
  }

  T dequeue( void )
  {
    if (s2.empty()) {
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
    }

    T elem = s2.top();
    s2.pop();

    return elem;
  }

  int Size( void ) const { return s1.size() + s2.size();}
  bool isEmpty( void ) const {return s1.empty() && s2.empty();}

  Queue<T>& operator=( const Queue& q )
  {
    while (!s1.empty()) {
        s1.pop();
    }
    s1 = q.s1;

    while (!s2.empty()) {
        s2.pop();
    }
    s2 = q.s2;
  }

  //
  // Error Class
  //
  class xEmpty{ };

private:
    // private data
    std::stack<T> s1;
    std::stack<T> s2;
};

#endif /* QUEUE_H_ */
