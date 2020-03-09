#ifndef TEMPLATE_SOLUTION_H
#define TEMPLATE_SOLUTION_H

#include <string>
#include <vector>
#include <map>
#include <unordered_set>
#include <set>
#include <stack>

class Graph {
public:
  Graph(std::map <int, std::unordered_set<int>> &vertices) : v_(vertices) {}
  std::map <int, std::unordered_set<int>> v_;

  std::set <int> findRootNodes();
  std::vector <int> topological_sort(int root);
  void DFS_node(int node, std::vector <bool> &visited);
};

#endif