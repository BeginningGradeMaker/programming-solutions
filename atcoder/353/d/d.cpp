#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll INF = 0x3f3f3f3f;
ll mod = 998244353;

vector<ll> p = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000, 10000000000};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // Input handling goes here
    ll N; cin >> N;
    vector<ll> A(N);
    for (ll &x : A) cin >> x;

    auto len = [&] (ll n) {
        ll cnt = 0;
        while (n > 0) {
            n /= 10;
            cnt++;
        }

        return cnt;
    };

    ll sum = A[0];
    ll ans = 0;
    for (ll i = 1; i < N; i++) {
        ans += A[i] * i % mod;
        ll n = len(A[i]);
        ans += sum * (p[n] % mod) % mod;
        sum += A[i];
        sum %= mod;
        ans %= mod;
    }

    cout << ans % mod << endl;
}
