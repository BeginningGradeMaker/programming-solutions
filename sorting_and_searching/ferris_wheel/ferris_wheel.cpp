#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int mod = 1000000007;

int main() {
    // solution goes here
    int n, x; cin >> n >> x;
    vector<int> children(n);

    for (int i = 0; i < n; i++) {
    cin >> children[i];
    }

    sort(children.begin(), children.end());

    int i = 0, j = n-1;

    int cnt = 0;
    while (i <= j) {
        if (children[i] + children[j] <= x) {
            i++;
            j--;
        } else {
            j--;
        }
        cnt++;
    }

    cout << cnt << endl;
}
