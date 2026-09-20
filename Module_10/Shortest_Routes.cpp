#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n, e, q;
    cin >> n >> e >> q;

    long long adj_mat[n + 5][n + 5];

    // Initialize
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == j)
                adj_mat[i][j] = 0;
            else
                adj_mat[i][j] = LLONG_MAX;
        }
    }

    // Input edges
    while (e--)
    {
        long long a, b, c;
        cin >> a >> b >> c;

        adj_mat[a][b] = min(adj_mat[a][b], c);
        adj_mat[b][a] = min(adj_mat[b][a], c);
    }

    // Floyd-Warshall
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (adj_mat[i][k] != LLONG_MAX &&
                    adj_mat[k][j] != LLONG_MAX &&
                    adj_mat[i][k] + adj_mat[k][j] < adj_mat[i][j])
                {
                    adj_mat[i][j] = adj_mat[i][k] + adj_mat[k][j];
                }
            }
        }
    }

    // Queries
    while (q--)
    {
        long long s, d;
        cin >> s >> d;

        if (adj_mat[s][d] == LLONG_MAX)
            cout << -1 << '\n';
        else
            cout << adj_mat[s][d] << '\n';
    }

    return 0;
}