
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool contains(const priority_queue<pair<int, int>> &ipq, int neighborTo)
{
}

vector<int> dijkstra(const vector<vector<pair<int, int>>> &g, int N, int s)
{
    vector<bool> visited(N, false);
    vector<int> dist(N, INT_MAX); // puede ser double
    // comparar
    // saber si 2 números flotantes a y b son iguales, se debería calcular: fabs(a-b) <= epsilon [definido como constante 10^-6 margen de error]
    dist[s] = 0;
    priority_queue<pair<int, int>> ipq;
    ipq.push(pair<int, int>(0, s));
    while (ipq.size() != 0)
    {
        auto t = ipq.top();
        int index = t.second;
        int minValue = -t.first;
        if (!visited[index])
        {
            for (auto neighbor : g[index])
            {
                if (visited[neighbor.first])
                    continue;
                int newDist = dist[index] + neighbor.second;
                if (newDist < dist[neighbor.first])
                {
                    dist[neighbor.first] = newDist;
                    ipq.push(pair<int, int>(-newDist, neighbor.first));
                    /*if (!contains(ipq, neighbor.first)) //eager
                    {
                        ipq.push(pair<int, int>(newDist,neighbor.first));
                    }
                    else
                    {
                        ipq.decreaseKey(neighbor.first, newDist);
                    }*/
                }
            }
            visited[index] = true;
        }
    }
    return dist;
}

int main()
{
}