#include "solution.h"
#include <queue>

void Graph::DFS_node(int node, std::vector<bool> &vertices_visited)
{
  if (vertices_visited[node] != true)
  {
    vertices_visited[node] = true;
  }

  for (auto it = v_.at(node).begin(); it != v_.at(node).end(); it++)
  {
    if (vertices_visited[*it] != true)
      DFS_node(*it, vertices_visited);
  }
}

std::set<int> Graph::findRootNodes()
{
  std::set<int> result;
  if (v_.empty())
    return result;

  std::vector<int> indegree(v_.size(), 0);

  for (auto it = v_.begin(); it != v_.end(); it++)
  {
    for (auto &n : it->second)
    {
      indegree[n]++;
    }
  }

  for (unsigned int i = 0; i < indegree.size(); i++) {
    if (indegree[i] == 0)
      result.insert(i);
  }

  return result;
}

std::vector<int> Graph::topological_sort(int root)
{
  std::vector<int> result;
  if (v_.empty())
    return result;

  std::queue<int> node_queue;
  std::map<int, int> marks;
  std::vector<int> indegree(v_.size(), 0);

  for (auto it = v_.begin(); it != v_.end(); it++)
  {
    for (auto &n : it->second)
    {
      indegree[n]++;
    }
  }

  for (unsigned int i = 0; i < indegree.size(); i++)
  {
    if (indegree[i] == 0)
      node_queue.push(i);
  }

  while (!node_queue.empty())
  {
    int current = node_queue.front();
    node_queue.pop();
    result.push_back(current);

    for (auto &n : v_[current])
    {
      if (--indegree[n] == 0)
        node_queue.push(n);
    }
  }

  return result;
}