#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    // solution goes here
    ll n;

    cin >> n;

    for (ll i = 1; i <= n; i++) {
        cout << (i * i * (i * i - 1)) / 2 - 4 * (i - 1) * (i - 2) << '\n';
    }    
}
