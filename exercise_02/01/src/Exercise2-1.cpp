#include "string.h"

int main(int argc, char* argv[]) {
    std::cout << std::endl;

    String s1, s2("some text");
    s1 = "new text";
    String* s3 = new String(" ");
    String s4 = s2;
    delete s3;
    s1[5] = s2[7];

    return 0;
}
