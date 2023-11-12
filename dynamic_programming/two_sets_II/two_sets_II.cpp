#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int mod = 1000000007;

// 0/1 knapsack
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    // solution goes here
    int n; cin >> n;
    int target = n*(n+1)/2;
    if (target % 2) {
        cout << 0 << endl;
        return 0;
    }
    target /= 2;

    // dp[i][j] = the number of ways to get sum j using nums 1...i (to force we only count each pair of sets once)
    vector<vector<int>> dp(n, vector<int>(target+1, 0));
    for (int i = 0; i < n; i++) {
        dp[i][0] = 1;
    }

    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= target; j++) {
            dp[i][j] = dp[i-1][j];
            if (j - i >= 0) {
                dp[i][j] += dp[i-1][j-i];
                dp[i][j] %= mod;
            }
        }
    }

    cout << dp[n-1][target] << endl;
}
