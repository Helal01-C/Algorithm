#include <bits/stdc++.h>
using namespace std;
int leader[1005];
int group_size[1005];

int find(int node) // O(logN)
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
    memset(leader, -1, sizeof(leader));
    memset(group_size, 1, sizeof(group_size));

    int n, e;
    cin >> n >> e;
    bool cycle = false;
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        int leaderA = find(a);
        int leaderB = find(b);

        if (leaderA == leaderB)
        {
            cycle = true;
        }
        else
        {
            Dsu_union(a, b);
        }
    }
    if (cycle)
        cout << "Cycle";
    else
        cout << "No Cycle";
    return 0;
}