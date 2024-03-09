#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int mod = 1000000007;

int main() {
    // solution goes here
    int n, x;
    cin >> n >> x;
    vector<int> coins(n);

    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    vector<int> dp(x + 1, 0);

    dp[0] = 1;
    for (auto coin : coins) {
        for (int money = 1; money <= x; money++) {
            if (money - coin >= 0) {
                dp[money] += dp[money - coin];
                if (dp[money] >= mod) {
                    dp[money] -= mod;
                }
            }
        }
    }

    cout << dp[x];
}
