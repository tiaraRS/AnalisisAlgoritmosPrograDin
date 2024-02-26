#include <iostream>
#include <vector>

using namespace std;

vector<vector<pair<int, int>>> g; // orig, residual
vector<vector<int>> gRes;         // capacidad rem

vector<int> dfs(int s, int t)
{
}

vector<int> getNeighbors(int current)
{
    vector<int> neighbors;
    int i = 0;
    while (i < g[current].size())
    {
        if (g[current][i] != NULL)
            neighbors.push_back(i);
        i++;
    }
}

int getMinFlow(int s, vector<int> path)
{
    int minFlow = gRes[s][path[0]];
    for (int i = 1; i < path.size(); i++)
    {
        minFlow = min(minFlow, gRes[s][path[i]]);
    }
    return minFlow;
}

bool hasAugmentingPaths(int s, vector<int> neighbors)
{
    bool hasAugmentingPs = true;
    int i = 0;
    while (hasAugmentingPs)
    {
        hasAugmentingPs = gRes[s][neighbors[i]] > 0;
        i++;
    }
    return hasAugmentingPs;
}

int fordFulkerson(int s, int t)
{
    vector<int> neighbors = getNeighbors(s);
    int i = 0;
    int maxFlow = 0;
    while (hasAugmentingPaths(s, neighbors))
    {
        vector<int> path = dfs(s, t);
        maxFlow += getMinFlow(s, path);
        i++;
    }
    return maxFlow;
}

int main()
{
}