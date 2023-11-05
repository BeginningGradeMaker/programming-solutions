#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int mod = 1000000007;

int main() {
    // solution goes here
    ll b;
    cin >> b;

    for (ll a = 1; a <= 16; a++) {
        if ((ll)pow(a, a) == b) {
            cout << a << endl;
            return 0;
        }
    }

    cout << -1 << endl;
}
