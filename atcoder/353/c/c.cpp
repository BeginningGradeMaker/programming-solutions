#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll INF = 0x3f3f3f3f;
ll mod = 1e8;
ll N = 200005;

void solve() {
    // Solution goes here
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // Input handling goes here
    ll N; cin >> N;
    vector<ll> A(N);
    

    ll ans = 0;
    for (ll &x : A) {
        cin >> x;
        ans += x * (N-1); 
        // ans %= mod;
    }

    vector<ll> B(N);
    ll cnt = 0;
    sort(A.begin(), A.end());
    while (!A.empty()) {
        ll x = A.back(); A.pop_back();
        cnt += A.size() - (lower_bound(A.begin(), A.end(), mod - x) - A.begin());
    }

    ans -= mod * cnt;

    cout << ans << endl;
}
