#include "string.h"

int main(int argc, char* argv[]) {
    String s1, s2("some text");

    std::cout << "Value of s1 now: " << s1 << std::endl;
    std::cout << "Value of s2 now: " << s2 << std::endl;

    s1 = "new text";
    
    std::cout << "Value of s1 now: " << s1 << std::endl;

    String* s3 = new String(" ");
    
    std::cout << "Value of s3 now: " << s3 << std::endl;

    String s4 = s2;
    
    std::cout << "Value of s4 now: " << s4 << std::endl;

    /*
    delete s3;
    s1[5] = s2[7];
    */

    return 0;
}
