#include <iostream>
#include <vector>
#include <stack>
#define UNVISITED -1

using namespace std;

int N;
vector<bool> visited(N, false);
vector<int> ids(N, UNVISITED);
vector<int> low(N, 0);
stack<int> stackG;
vector<bool> onStack;
vector<vector<int>> g;
int id = 0;
int sccCount = 0;
void dfs(int current)
{
    // assert(ids[current]==UNVISITED) //asegurar que no este visitado
    stackG.push(current);
    onStack[current] = true;
    id++;
    ids[current] = id;
    low[current] = id;
    for (auto neighbor : g[current])
    {
        if (ids[neighbor] == UNVISITED)
            dfs(neighbor);
        if (onStack[neighbor])
            low[current] = min(low[current], low[neighbor]);
    }
    // after exploring all neighbors
    if (ids[current] == low[current])
    {
        int node = stackG.top(); // new scc
        while (stackG.top() != current)
        {
            node = stackG.top();
            stackG.pop();
            onStack[node] = false;
            low[node] = ids[current];
        }
        stackG.pop(); // remove current from stack
        sccCount++;
    }
}

vector<int> findSCCs()
{ // lista de adyacencia
    for (int i = 0; i < N; i++)
    {
        if (ids[i] == UNVISITED)
        {
            dfs(i);
        }
    }
    return low;
}

int main()
{
}