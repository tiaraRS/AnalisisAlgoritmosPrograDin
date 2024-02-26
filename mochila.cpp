#include <iostream>
using namespace std;
#include <vector>
int dp[100][100]; //=-1
vector<int> pesos;
vector<int> valores;
// ENFOQUE TOP-DOWN: resolver subproblemas a medida que se necesita, de grande a peq
int mochila(int i, int K)
{
    if (dp[i][K] != -1)
        return dp[i][K];
    if (pesos[i] > K)
    {
        dp[i][K] = mochila(i - 1, K);
    }
    else
    {
        dp[i][K] = max(mochila(i - 1, K), valores[i] + mochila(i - 1, K - pesos[i]));
    }
    return dp[i][K];
}

// ENFOQUE BOTTOM-UP: calcular subproblemas en orden, de peq a grande
int mochila(int K)
{
    int ans = 0;
    while (ans < K)
    {
    }
    for (int i = 0; i < n; i++)
    {
        if (pesos[i] <= K)
        {
            ans = max(dp[i - 1][K], dp[i - 1][K]);
        }
    }
    if (dp[i][K] != -1)
        return dp[i][K];
    if (pesos[i] > K)
    {
        dp[i][K] = mochila(i - 1, K);
    }
    else
    {
        dp[i][K] = max(mochila(i - 1, K), valores[i] + mochila(i - 1, K - pesos[i]));
    }
    return dp[i][K];
}