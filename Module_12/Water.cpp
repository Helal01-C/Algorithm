#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<int> h(n);
        for (int i = 0; i < n; i++) {
            cin >> h[i];
        }
        int first = 0;
        int second = 1;
        if (h[second] > h[first]) {
            swap(first, second);
        }
        for (int i = 2; i < n; i++) {

            if (h[i] > h[first]) {
                second = first;
                first = i;
            }
            else if (h[i] > h[second]) {
                second = i;
            }
        }
        if (first < second)
            cout << first << " " << second << endl;
        else
            cout << second << " " << first << endl;
    }

    return 0;
}