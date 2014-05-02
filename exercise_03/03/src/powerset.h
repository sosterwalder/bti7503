#ifndef __POWERSET_H__
#define __POWERSET_H__

#include <set>
#include <vector>
#include <math.h>

template <typename T>
class Powerset {
    public:
        static std::set<std::set<T>> powerset(const std::set<T>& inputSet, std::set<std::set<T>>& resultSet)
        {
            resultSet.insert(inputSet);

            for (auto it = inputSet.begin(); it != inputSet.end(); ++it) {
                // Clone set
                std::set<T> tempSet(inputSet);

                // Erase current element
                tempSet.erase(*it);

                // Recursion \o/
                powerset(tempSet, resultSet);
            }

            return resultSet;
        }

        static void output(const std::set<std::set<T>>& powerSet)
        {
            std::cout << std::endl;
            std::cout << "Ohai, this could take a while.." << std::endl;
            std::cout << "Please hang on.. :)" << std::endl;
            std::cout << std::endl;

            for (auto sets = powerSet.begin(); sets != powerSet.end(); ++sets) {
                std::cout << "{";
                std::string prefix = "";

                for (auto set = sets->begin(); set != sets->end(); ++set) {
                    std::cout << prefix << *set;
                    prefix = ",";
                }
                std::cout << "}" << std::endl;
            }
        }
};

#endif /* __POWERSET_H__ */
