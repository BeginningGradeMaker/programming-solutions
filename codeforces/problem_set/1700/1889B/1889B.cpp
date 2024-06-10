#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int INF = 0x3f3f3f3f;
int mod = 1e9 + 7;
int N = 200005;

void solve() {
    // Solution goes here
    ll n, c; cin >> n >> c;
    vector<ll> a(n);
    for (ll &x : a) cin >> x;

    // Claim: if we can connect two vertices a_i, a_j 
    // in different compoenents, where i, j != 1. Then
    // we can connect vertex 1 with one of i, j.
    // Proof: Let s_i be the sum of vertices weight in
    // the component of s_i. Assume vertices i, j can be 
    // connected where i, j != 1. Then 
    //          s_i + s_j >= i * j * c 
    //                    >= (i + j) * c
    //                    = i * c + j * c
    // then we must have s_i >= i * c or s_j >= j * c,
    // otherwise we would have s_i + s_j < i * c + j * c,
    // a contradiction.
    // WLOG say s_i >= i * c. Then s_i + a_1 >= i * c * 1,
    // so vertex i and vertex 1 can be connected.
    //
    // Therefore, to check if we can connect all vertices,
    // we can greedily check if we can connect vertex 1 to
    // all other vertices.
    vector<ll> idx(n-1);

    iota(idx.begin(), idx.end(), 1);
    sort(idx.begin(), idx.end(), [&] (ll i, ll j) {
        return (i+1) * c - a[i] < (j+1) * c - a[j];
    });

    ll sum = a[0];
    for (ll i : idx) {
        if (sum + a[i] < (i+1) * c) {
            cout << "No" << endl;
            return;
        }

        sum += a[i];
    }

    cout << "Yes" << endl;
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
