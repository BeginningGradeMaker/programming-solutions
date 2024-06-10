#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int INF = 0x3f3f3f3f;
int mod = 1e9 + 7;
int N = 200005;

void solve() {
    // Solution goes here
    int n; cin >> n;
    vector<int> arr(n);

    for (int &x : arr) cin >> x;

    unordered_map<int, unordered_map<int, int>> M;
    unordered_map<int, unordered_map<int, unordered_map<int, int>>> cnt;

    ll ans = 0;
    for (int i = 0; i < n - 2; i++) {
        ans += M[arr[i]][arr[i+1]] - cnt[arr[i]][arr[i+1]][arr[i+2]];
        M[arr[i]][arr[i+1]]++;
        cnt[arr[i]][arr[i+1]][arr[i+2]]++;
    }

    M.clear();
    cnt.clear();


    for (int i = 0; i < n - 2; i++) {
        ans += M[arr[i]][arr[i+2]] - cnt[arr[i]][arr[i+2]][arr[i+1]];
        M[arr[i]][arr[i+2]]++;
        cnt[arr[i]][arr[i+2]][arr[i+1]]++;
    }

    M.clear();
    cnt.clear();
    for (int i = 0; i < n - 2; i++) {
        ans += M[arr[i+1]][arr[i+2]] - cnt[arr[i+1]][arr[i+2]][arr[i]];
        M[arr[i+1]][arr[i+2]]++;
        cnt[arr[i+1]][arr[i+2]][arr[i]]++;
    }


    cout << ans << endl;
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
