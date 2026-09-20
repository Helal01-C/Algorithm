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

    Dsu_union(1, 2);
    Dsu_union(2, 0);
    Dsu_union(3, 1);
    for (int i = 0; i < 6; i++)
        cout << i << "->" << leader[i] << endl;
    return 0;
}