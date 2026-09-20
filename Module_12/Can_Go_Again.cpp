#include <bits/stdc++.h>
using namespace std;

class Edge
{
public:
    int a, b;
    long long w;

    Edge(int a, int b, long long w)
    {
        this->a = a;
        this->b = b;
        this->w = w;
    }
};

int n, e;
long long dis[1005];

vector<Edge> edge_list;

bool bellman_ford(int src)
{
    for (int i = 1; i <= n; i++)
    {
        dis[i] = LLONG_MAX;
    }
    dis[src] = 0;
    for (int i = 1; i <= n - 1; i++)
    {
        for (auto ed : edge_list)
        {
            int a = ed.a;
            int b = ed.b;
            long long w = ed.w;

            if (dis[a] != LLONG_MAX &&
                dis[a] + w < dis[b])
            {
                dis[b] = dis[a] + w;
            }
        }
    }
    for (auto ed : edge_list)
    {
        int a = ed.a;
        int b = ed.b;
        long long w = ed.w;

        if (dis[a] != LLONG_MAX &&
            dis[a] + w < dis[b])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    cin >> n >> e;

    while (e--)
    {
        int a, b;
        long long w;

        cin >> a >> b >> w;

        edge_list.push_back(Edge(a, b, w));
    }

    int source;
    cin >> source;
    bool possible = bellman_ford(source);
    if (!possible)
    {
        cout << "Negative Cycle Detected\n";
        return 0;
    }
    int t;
    cin >> t;
    while (t--)
    {
        int dest;
        cin >> dest;

        if (dis[dest] == LLONG_MAX)
            cout << "Not Possible\n";
        else
            cout << dis[dest] << '\n';
    }
    return 0;
}