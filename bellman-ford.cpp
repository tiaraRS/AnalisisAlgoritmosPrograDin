#include <iostream>
#include <vector>
#include <queue>
#define epsilon 10e-6
using namespace std;

bool lessThan(double a, double b)
{
    return fabs(a - b) <= epsilon;
}

void bellmanFord(vector<double> &D, const vector<vector<pair<int, double>>> &g, int V)
{
    for (int i = 0; i < V - 1; i++)
    {
        for (auto neighbor : g[i])
        {
            if (lessThan(D[i] + neighbor.second, D[neighbor.first]))
                D[neighbor.first] = D[i] + neighbor.second;
        }
    }

    for (int i = 0; i < V - 1; i++)
    {
        for (auto neighbor : g[i])
        {
            if (lessThan(D[i] + neighbor.second, D[neighbor.first]))
                D[neighbor.first] = -DBL_MIN;
        }
    }
}

int main()
{
}