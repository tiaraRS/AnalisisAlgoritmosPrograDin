#include <iostream>
using namespace std;

int n;
int dp[1000][1000];
int shortestPath[1000][1000];

void setup(int m[100][100])
{
}

void propagateNegativeCyclesPath()
{
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (dp[i][k] + dp[k][j] < dp[i][j])
                {
                    dp[i][j] = INT_MIN;
                    shortestPath[i][j] = shortestPath[i][k];
                }
            }
        }
    }
}

int floydWarshal(int m[100][100])
{
    setup(m);
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (dp[i][k] + dp[k][j] < dp[i][j])
                {
                    dp[i][j] = dp[i][k] + dp[k][j];
                    shortestPath[i][j] = shortestPath[i][k];
                }
            }
        }
    }
    propagateNegativeCyclesPath();
}

int main()
{
}