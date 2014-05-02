#include <string>
#include <iostream>

#include "exception.h"
#include "Queue.h"

int main(int argc, char* argv[]) {
    try {
        Queue<int> queueOfInt;
        Queue<int> queueOfInt2;


        queueOfInt.enqueue(1);
        queueOfInt.enqueue(2);
        queueOfInt.enqueue(3);
        queueOfInt.enqueue(4);

        std::cout << "Queue: " << queueOfInt.dequeue() << std::endl;

        queueOfInt.enqueue(5);
        queueOfInt.enqueue(5);
        queueOfInt.enqueue(600);
        queueOfInt.enqueue(5);
        queueOfInt.enqueue(500);

        queueOfInt2 = queueOfInt;

        std::cout << "Queue: " << queueOfInt.dequeue() << std::endl;

        while (!queueOfInt.isEmpty()) {
            std::cout << "Queue: " << queueOfInt.dequeue() << std::endl;
        }

        queueOfInt.enqueue(9999);

        while (!queueOfInt2.isEmpty()) {
            std::cout << "Queue2: " << queueOfInt2.dequeue() << std::endl;
        }


        Queue<float> queueOfFloat;
        Queue<std::string> queueOfString;

    }

    catch (OutOfBoundsException& ex) {
        std::cout << "An exception occured: " << ex.what() << std::endl;
    }

    return 0;
}
