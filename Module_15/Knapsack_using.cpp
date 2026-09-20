#include <bits/stdc++.h>
using namespace std;
int val[1005], wight[1005];
int dp[1005][1005];

int knapsack(int i, int mx_weight)
{
    if (i < 0 || mx_weight <= 0)
        return 0;

    if (dp[i][mx_weight] != -1)
      return dp[i][mx_weight];
    if(wight[i] <= mx_weight)
    {
        int op1 = knapsack(i - 1, mx_weight - wight[i]) + val[i];
        int op2 = knapsack(i - 1, mx_weight);
        dp[i][mx_weight] = max(op1,op2);
        return dp[i][mx_weight];
    }
    else
    {
        dp[i][mx_weight] = knapsack(i-1,mx_weight);
        return knapsack(i - 1, mx_weight);
    }
}
int main()
{
    int n, mx_wight;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> val[i];
    for (int i = 0; i < n; i++)
        cin >> wight[i];
    cin >> mx_wight;

    cout << knapsack(n - 1, mx_wight);
    return 0;
}