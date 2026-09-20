#include <bits/stdc++.h>
using namespace std;
int leader[1005];
int group_size[1005];

int find(int node)
{
    if (leader[node] == -1)
    {
        return node;
    }
    int mainleader = find(leader[node]);
    leader[node] = mainleader;
    return mainleader;
}
void Dsu_union(int node1, int node2)
{
    int mainleader1 = find(node1);
    int mainleader2 = find(node2);
    if (group_size[mainleader1] > group_size[mainleader2])
    {
        leader[mainleader2] = mainleader1;
        group_size[mainleader1] += group_size[mainleader2];
    }
    else
    {
        leader[mainleader1] = mainleader2;
        group_size[mainleader2] += group_size[mainleader1];
    }
}
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        leader[i] = -1;
        group_size[i] = 1;
    }
    vector<pair<int, int>> rmv;
    vector<pair<int, int>> create;
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        int leaderA = find(a);
        int leaderB = find(b);
        if (leaderA == leaderB)
        {
            rmv.push_back({a, b});
        }
        else
        {
            Dsu_union(a, b);
        }
    }
    for (int i = 0; i <= n; i++)
    {
        int leaderC = find(1);
        int leaderD = find(i);
        if (leaderC != leaderD)
        {
            create.push_back({1, i});
            Dsu_union(1, i);
        }
    }
    cout << rmv.size() << endl;
    for (int i = 0; i < rmv.size(); i++)
    {
        cout << rmv[i].first << " " << rmv[i].second << " " << create[i].first << " " << create[i].second << endl;
    }
    return 0;
}