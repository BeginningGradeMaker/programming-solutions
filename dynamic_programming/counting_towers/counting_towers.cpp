#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int mod = 1000000007;

int main() {
    // solution goes here
    int t;
    cin >> t;
    vector<ll> nums(t);

    for (int i = 0; i < t; i++) {
        cin >> nums[i];
    }
    int n = *max_element(nums.begin(), nums.end());

    vector<vector<ll>> dp(2, vector<ll>(n + 1));
    dp[0][1] = 1; 
    dp[1][1] = 1;
    for (int i = 2; i <= n; i++) {
        dp[0][i] = (dp[0][i - 1] * 2 + dp[1][i-1]);
        while (dp[0][i] >= mod) dp[0][i] -= mod;
        dp[1][i] = (dp[1][i - 1] * 4 + dp[0][i-1]) % mod;
        while (dp[1][i] >= mod) dp[1][i] -= mod;
    }

    for (int i = 0; i < t; i++) {
        ll ans = dp[0][nums[i]] + dp[1][nums[i]];
        while (ans >= mod) ans -= mod;
        cout << ans << endl;
    }
}
