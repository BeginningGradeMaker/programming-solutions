#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int mod = 1000000007;

int main() {
    // solution goes here
    int n;
    cin >> n;
    vector<int> nums(n);
    vector<unordered_set<ll>> dp(n);

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    dp[0].insert(nums[0]);
    for (int i = 1; i < n; i++) {
        dp[i].insert(nums[i]);
        for (ll num : dp[i - 1]) {
            dp[i].insert(num);
            dp[i].insert(num + nums[i]);
        }
    }

    set<ll> ans(dp[n-1].begin(), dp[n-1].end());
    cout << ans.size() << endl;
    for (ll num : ans) {
        cout << num << ' ';
    }
    cout << endl;
}
