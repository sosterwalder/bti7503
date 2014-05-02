#include <string>
#include <iostream>

#include "exception.h"
#include "array.h"

int main(int argc, char* argv[]) {
    try {
        Array<int, 20> arrayOfInt = {1, 2 ,4, 8};
        std::cout << "Array<int>.at(2) is: " << arrayOfInt.at(2) << std::endl;
        std::cout << "Array<int>[2] is: " << arrayOfInt[2] << std::endl;
        std::cout << "Array<int>.at(9) is: " << arrayOfInt.at(9) << std::endl;
        std::cout << "Array<int>[9] is: " << arrayOfInt[9] << std::endl;
        std::cout << "Array<int>.at(-200) is: " << arrayOfInt.at(-200) << std::endl;
    }
    catch (OutOfBoundsException& ex) {

        std::cout << "An exception occured: " << ex.what() << std::endl;
    }

    try {
        Array<std::string, 6> arrayOfString = {"hello", "foo", "bar", "baz"};
        Array<std::string, 6>::iterator arrayOfStringItr;
        Array<std::string, 6> arrayOfString2 = {"hello2", "foo2", "bar2", "baz2"};
        
        std::cout << "Array<string>[2] is: " << arrayOfString[2] << std::endl;
        std::cout << "Array<string>[3] is: " << arrayOfString[3] << std::endl;
        std::cout << "Array2<string>[2] is: " << arrayOfString2[2] << std::endl;
        std::cout << "Array2<string>[3] is: " << arrayOfString2[3] << std::endl;

        std::cout << "Array<string>[5] is: " << arrayOfString[5] << std::endl;
        
        std::cout << "Swapping Array<string> with Array2<string>." << std::endl;
        arrayOfString.swap(arrayOfString2);

        std::cout << "Array<string>[2] is: " << arrayOfString[2] << std::endl;
        std::cout << "Array<string>[3] is: " << arrayOfString[3] << std::endl;
        std::cout << "Array2<string>[2] is: " << arrayOfString2[2] << std::endl;
        std::cout << "Array2<string>[3] is: " << arrayOfString2[3] << std::endl;


        std::cout << "Testing iterator of Array<string>." << std::endl;

        size_t i = 0;
        for (   arrayOfStringItr = arrayOfString.begin();
                arrayOfStringItr != arrayOfString.end();
                ++arrayOfStringItr
            ) {
            std::cout << "Element " << i << " of Array<string> is: " << *arrayOfStringItr << std::endl;
            ++i;
        }
    }

    catch (OutOfBoundsException& ex) {
        std::cout << "An exception occured: " << ex.what() << std::endl;
    }

    return 0;
}
