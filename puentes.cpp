#include <iostream>
#include <vector>

using namespace std;
int id = 0;
void dfs(int current, int parent, vector<bool> &visited, vector<int> &ids, vector<int> &low, vector<pair<int, int>> &bridges, const vector<vector<int>> &g)
{
    visited[current] = true;
    id++;
    ids[current] = id;
    low[current] = ids[current];
    for (auto neighbor : g[current])
    {
        if (neighbor == parent)
            continue;
        if (!visited[neighbor])
        {
            dfs(neighbor, parent, visited, ids, low, bridges, g);
            low[current] = min(low[current], low[neighbor]);
            if (ids[current] < low[neighbor])
            {
                bridges.push_back(pair<int, int>(current, neighbor));
            }
        }
        else
        {
            low[current] = min(low[current], ids[neighbor]);
        }
    }
}

vector<pair<int, int>> findBridges(vector<vector<int>> g, int N)
{ // lista de adyacencia
    vector<bool> visited(N, false);
    vector<int> ids(N, 0);
    vector<int> low(N, 0);
    vector<pair<int, int>> bridges;
    for (int j = 0; j < N; j++)
    {
        if (!visited[j])
        {
            dfs(j, -1, visited, ids, low, bridges, g);
        }
    }
    return bridges;
}

int main()
{
}