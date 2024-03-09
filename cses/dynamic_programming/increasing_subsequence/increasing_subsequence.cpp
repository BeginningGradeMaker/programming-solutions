#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int mod = 1000000007;

int main() {
    // solution goes here
    int n; cin >> n;
    vector<int> nums(n);

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    /*
    At each iteration i,
    dp[k] = the smallest ending number among nums[1...i-1] among
            all increasing subsequence of length k
    */
    vector<int> dp(n + 1, INT_MAX);


    /*
    Note that 
    1. dp[i] < dp[i + 1] (can be shown by contradiction).
    2. 
    */
    int ans = 0;
    dp[0] = 0;
    for (int i = 0; i < n; i++) {
        int k = upper_bound(dp.begin(), dp.end(), nums[i]) - dp.begin();

        if (dp[k - 1] < nums[i] && dp[k] > nums[i]) {
            dp[k] = nums[i];
            ans = max(ans, k);
        }
    }

    // for (int i = 0; i <= n; i++) {
    //     if (dp[i] < 200006) ans = i;
    // }

    cout << ans;
}
