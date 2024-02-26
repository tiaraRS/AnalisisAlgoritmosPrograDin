#include <iostream>
#include <vector>

using namespace std;

void dfs(int current, vector<bool> &visited, vector<int> &visitedNodes, const vector<vector<int>> &g)
{ // pasar el ordering
    visited[current] = true;

    for (auto neighbor : g[current])
    {
        if (!visited[neighbor])
            dfs(neighbor, visited, visitedNodes, g);
    }

    visitedNodes.push_back(current);
    // insertar nodo a ordering ref
    // i global o por referencia
}

vector<int> topSort(vector<vector<int>> g, int N)
{ // lista de adyacencia
    vector<bool> visited(N, false);
    vector<int> ordering(N, 0);
    vector<int> visitedNodes;
    int i = N - 1;

    for (int j = 0; j < N; j++)
    {
        if (!visited[j])
        {
            visitedNodes.clear();
            dfs(j, visited, visitedNodes, g);
            for (auto nodeId : visitedNodes)
            {
                ordering[i] = nodeId;
                i--;
            }
        }
    }
    return ordering;
}

int main()
{
}