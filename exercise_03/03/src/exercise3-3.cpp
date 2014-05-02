#include <string>
#include <set>
#include <iostream>

#include "powerset.h"

int main() {
    std::cout << std::endl;
    std::cout << "Oh hello there.. please be patient, power set " << std::endl;
    std::cout << "calculation may take a while.." << std::endl;
    std::cout << "at least with > 7 elements." << std::endl;
    std::cout << "Combinatoric explosion and stuff.. :)" << std::endl;


    std::set<int> intSet = {0, 1, 2, 3, 4};
    std::set<std::string> stringSet = {"x", "y", "z", "a", "b", "c", "foo", "baz"};

    std::cout << std::endl;

    for (auto it = intSet.begin(); it != intSet.end(); ++it) {
        std::cout << "Int-set element at #" << distance(intSet.begin(), it) << ": " << *it << std::endl;
    }

    std::set<std::set<int>> intPowerset;
    Powerset<int>::powerset(intSet, intPowerset);
    Powerset<int>::output(intPowerset);

    std::cout << std::endl;

    for (auto it = stringSet.begin(); it != stringSet.end(); ++it) {
        std::cout << "String-set element at #" << distance(stringSet.begin(), it) << ": " << *it << std::endl;
    }

    std::set<std::set<std::string>> stringPowerset;
    Powerset<std::string>::powerset(stringSet, stringPowerset);
    Powerset<std::string>::output(stringPowerset);
}
