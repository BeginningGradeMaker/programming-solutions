#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int INF = 0x3f3f3f3f;
int mod = 1e9 + 7;
int N = 200005;

void solve() {
    // Solution goes here
    vector<int> v(3);
    for (int i = 0; i < 3; i++) cin >> v[i];

    for (int i = 0; i < 5; i++) {
        (*min_element(v.begin(), v.end()))++;
    }

    cout << v[0] * v[1] * v[2] << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // Input handling goes here
    int t; cin >> t;
    while (t--) {
        solve();
    }
}
