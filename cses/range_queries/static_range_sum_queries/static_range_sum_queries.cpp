#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int mod = 1000000007;

int main() {
    // solution goes here
    int n, m;
    cin >> n >> m;
    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    vector<ll> pre(n+1);
    pre[0] = 0;
    for (int i = 1; i <= n; i++) {
        pre[i] = (ll)arr[i-1] + pre[i-1];
    }

    for (int i = 0; i < m; i++) {
        int l, r;
        cin >> l >> r;
        cout << pre[r] - pre[l-1] << endl;
    }
}
