#include "src/lib/solution.h"
#include "gtest/gtest.h"
#include <vector>

TEST(DFSShould, DFSReturn)
{
  std::map<int, std::unordered_set<int>> vertices{
        {7, {6, 5}},
        {5, {4, 2}},
        {6, {4, 3}},
        {4, {}},
        {2, {1}},
        {3, {1}},
        {1, {0}},
        {0, {}}};

  Graph g(vertices);

  std::set<int> actual = g.findRootNodes();
  std::set<int> expected = {7};
  EXPECT_EQ(expected, actual);
}

TEST(DFS_ALLShould_1, DFS_ALLReturn_1)
{
  std::map<int, std::unordered_set<int>> vertices{};
  Graph g(vertices);

  std::set<int> actual = g.findRootNodes();
  std::set<int> expected = {};
  EXPECT_EQ(expected, actual);
}

TEST(DFSShould_2, DFSReturn_2)
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

  std::vector<int> actual = g.topological_sort(7);
  std::vector<int> expected = {7, 6, 5, 3, 4, 2, 1, 0};
  EXPECT_EQ(expected, actual);
}

TEST(DFS_ALLShould_3, DFS_ALLReturn_3)
{
  std::map<int, std::unordered_set<int>> vertices{};
  Graph g(vertices);

  std::vector<int> actual = g.topological_sort(7);
  std::vector<int> expected = {};
  EXPECT_EQ(expected, actual);
}