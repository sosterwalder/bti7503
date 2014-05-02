#include <typeinfo>
#include <string>
#include <array>
#include <iostream>
#include <iomanip>

#include "quicksort.h"

template <typename T, std::size_t SIZE>
void sortAndOutput(std::array<T, SIZE>& array)
{
    std::cout << std::endl;
    std::cout << "Got array of type: '" << typeid(T).name() << "'" << std::endl;

    std::cout << "Before sorting: " << std::endl;
    for (int i = 0; i < array.size(); i++) {
        std::cout << std::fixed << std::setprecision(6) << array[i] << " ";
    }
    std::cout << std::endl;

    Quicksort<T, SIZE>::quicksort(array, 0, array.size() - 1);

    std::cout << "After sorting: " << std::endl;
    for (int i = 0; i < array.size(); i++) {
        std::cout << std::fixed << std::setprecision(6) << array[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::array<int, 13> intArray = {77, 22, 1, 44, 22, -12, -1, 1, 13, 105, 12, 0, -4};
    std::array<float, 3> floatArray = {77.2001f, 77.900004f, -177.3028f};
    std::array<double, 3> doubleArray = {77.2001, 77.900004, -177.3028};
    std::array<std::string, 3> stringArray = {"foo", "bar", "baz"};

    sortAndOutput(intArray);
    sortAndOutput(floatArray);
    sortAndOutput(doubleArray);
    sortAndOutput(stringArray);
}
