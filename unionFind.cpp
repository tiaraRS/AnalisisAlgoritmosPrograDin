#include <iostream>
#include <vector>
using namespace std;

class UnionFind
{
    // constructor sizes inicializar cada clase con 1 elemento
private:
    vector<int> g;
    vector<int> sizes; // descendants -> inicializar (contar elems de cada clase)

public:
    void unionA(int a, int b)
    {
        int rootA = find(a);
        int rootB = find(b);
        if (rootA != rootB)
        {
            if (sizes[rootA] > sizes[rootB]) // agregamos al que tiene menos descendientes
            {
                g[rootA] = rootB;
                sizes[rootB] += sizes[rootA];
                sizes[rootA] = 0;
            }
            else
            {
                g[rootB] = rootA;
                sizes[rootA] += sizes[rootB];
                sizes[rootB] = 0;
            }
        }
    }

    int find(int a)
    {
        int root = -1;
        if (g[a] == a)
            return a;
        root = find(g[a]);
        g[a] = root; // path compression
        return root;
    }
};

int main()
{
}