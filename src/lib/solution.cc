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
  std::vector<bool> vertices(v_.size(), false);
  bool flag = true;

  if (v_.empty())
    return result;

  int root;
  for (unsigned i = 0; i < v_.size(); i++)
  {
    if (vertices[i] == false)
    {
      DFS_node(i, vertices);
      root = i;
    }
  }

  fill(vertices.begin(), vertices.end(), false);
  DFS_node(root, vertices);
  for (unsigned int i = 0; i < v_.size(); i++)
  {
    if (vertices[i] == false)
    {
      flag = false;
      break;
    }
  }
  if (flag == true)
    result.insert(root);

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