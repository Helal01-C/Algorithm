#include <bits/stdc++.h>
using namespace std;

int leader[10005];
int group_size[10005];

int find(int node)
{
    if (leader[node] == -1)
        return node;

    return leader[node] = find(leader[node]);
}
void Dsu_union(int node1, int node2)
{
    int leader1 = find(node1);
    int leader2 = find(node2);

    if (leader1 == leader2)
        return;

    if (group_size[leader1] > group_size[leader2])
    {
        leader[leader2] = leader1;
        group_size[leader1] += group_size[leader2];
    }
    else
    {
        leader[leader1] = leader2;
        group_size[leader2] += group_size[leader1];
    }
}

int main()
{
    int n, e;
    cin >> n >> e;
    memset(leader, -1, sizeof(leader));
    memset(group_size, 1, sizeof(group_size));
    int cycle_edges = 0;
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        if (find(a) == find(b))
        {
            cycle_edges++;
        }
        else
        {
            Dsu_union(a, b);
        }
    }
    cout << cycle_edges << endl;
    return 0;
}