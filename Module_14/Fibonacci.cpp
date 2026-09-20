#include <bits/stdc++.h>
using namespace std;

int fibbo(long long int n)
{
    if (n < 2)
        return n;
    return fibbo(n - 1) + fibbo(n - 2);
}
int main()
{
    cout << fibbo(50);
    return 0;
}