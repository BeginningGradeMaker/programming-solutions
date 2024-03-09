#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int mod = 1000000007;

int main() {
    // solution goes here
    int n, x;
    cin >> n >> x;
    map<int, int> mp;

    for (int i = 1; i <= n; i++) {
        int k; cin >> k;
        if (mp.count(x - k)) {
            cout << mp[x-k] << ' ' << i << endl;
            return 0;
        }
        mp[k] = i;
    }

    cout << "IMPOSSIBLE" << endl;
}
