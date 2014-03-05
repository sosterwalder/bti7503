/*
 * Turn all arguments in the following functions (only where it make sense)
 * into reference type arguments:
 *
 */

#include <iostream>

class Huge {
public:
  int key;
  int a[1000];
};

// The parameters were changed from
// Huge s1, Huge s2 into references.
//
// This provides the following advantages:
// * Assignment of NULL is not or only with
//   casting into a pointer possible
//
// * When one takes the address of a reference
//   he gets the address of the variable being referred to.
//   The address of a pointer would return the address of the
//   pointer variable
//
// * It is not possible to reassign a reference
int compareHuge(Huge& s1, Huge& s2) {
  return(s1.key > s2.key);
}

// Here the parameters have been changed too.
// Allthough I am not that sure if it really
// makes a huge difference as a temporary object
// needs to be created as well.
// But we have the same advantages as mentioned above.
void swapHuge(Huge& s1, Huge& s2) {
  Huge tmp(s1);
  s1 = s2;
  s2 = tmp;
}

void insertSortHuge(Huge *sa, unsigned int elems) {
  unsigned int j, k;

  for( k=1; k < elems; k++) {
    j = k;
    while( j > 0 && compareHuge( sa[j-1], sa[j] ) ) {
      swapHuge(sa[j-1], sa[j] ); j--;
    }
  }
}

int main() {
  Huge hugeArray[10];
  int ar[] = {17, 2, -3, 3, 4, 16, 1, 0, 23, 12, 1};

  for (int i = 0; i < 10; i++) {
    hugeArray[i].key = ar[i];
  }
  insertSortHuge(hugeArray, 10);
  for (int i = 0; i < 10; i++) {
    std::cout << hugeArray[i].key << std::endl;
  }
}
