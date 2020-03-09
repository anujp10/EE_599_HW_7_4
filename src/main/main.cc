#include <iostream>
#include "src/lib/solution.h"

int main()
{
    std::map<int, std::unordered_set<int>> vertices{
        {7, {5, 6}},
        {5, {2, 4}},
        {6, {3, 4}},
        {4, {}},
        {2, {1}},
        {3, {1}},
        {1, {0}},
        {0, {}}};

    Graph g(vertices);

    std::set <int> result = g.findRootNodes();

    for (auto &n : result)
        std::cout << n << " ";
    std::cout << std::endl;

    std::vector <int> out_sort = g.topological_sort(7);
    for (auto &n :out_sort)
        std::cout<< n << " ";
    std::cout << std::endl;
}
