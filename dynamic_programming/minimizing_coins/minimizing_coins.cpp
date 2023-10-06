#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    // solution goes here
    int n, x;
    cin >> n >> x;
    vector<int> nums(n);

    for (int i = 0; i < nums.size(); i++) {
        cin >> n;
        nums[i] = n;
    }

    vector<int> dp(x + 1, x + 1);

    dp[0] = 0;
    for (int i = 1; i <= x; i++) {
        for (auto coin : nums) {
            if (i - coin >= 0) {
                dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }
    }

    if (dp[x] == x + 1) cout << -1;
    else cout << dp[x];
}
