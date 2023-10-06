#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int mod = 1000000007;

int main() {
    // solution goes here
    int n; cin >> n;

    vector<ll> dp(n + 1, 0);

    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= 6; j++) {
            if (i - j >= 0) {
                dp[i] = (dp[i] + dp[i - j]) % mod;
            }
        }
    }

    cout << dp[n];
}
