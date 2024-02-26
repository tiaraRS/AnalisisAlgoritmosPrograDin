#include <iostream>
using namespace std;

#include <vector>

// ENFOQUE TOP-DOWN
vector<int> dp(100, -1);

int fib_TD(int n)
{
    if (n <= 1)
        return 1;
    else
    {
        if (dp[n] != -1)
        {
            dp[n] = fib_TD(n - 1) + fib_TD(n - 2);
        }
        return dp[n];
    }
}

// ENFOQUE BOTTOM-UP

int fib_BU(int n)
{
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}