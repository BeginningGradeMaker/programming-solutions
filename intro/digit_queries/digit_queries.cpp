#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int mod = 1000000007;

int get(ll n) {
    ll k = 1;
    ll tmp = 9;
    while (n > k * tmp) {
        // cout << "tmp: " << tmp << endl;
        // cout << "n: " << n << endl;
        n -= (k * tmp);
        k++;
        tmp *= 10;
    }
    // cout << "k: " << k << endl;
    // cout << "n: " << n << endl;
    if (k == 1) return n;
    else {
        ll m = (n - 1) / k;
        // cout << "m: " << m << endl;
        n = (n - 1) % k;
        // cout << "rem: " << n << endl;
        // cout << "base: " << pow(10, k-1) << endl;
        ll ans = (ll)pow(10, k-1) + m;
        // cout << "ans: " << ans << endl;
        return to_string(ans)[n] - '0';
    }
}

int main() {
    // solution goes here
    ll n; cin >> n;

    for (int i = 0; i < n; i++) {
        ll num; cin >> num;
        cout << get(num) << endl;
    }
}
