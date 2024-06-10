typedef long long ll;

class Solution {
    ll mod = 1e9 + 7;
public:
    /*int sumOfPower(vector<ll>& nums, ll k) {*/
    /*    // dp[i][j][k] = the number of subsequences of a_0, ... , a_i*/
    /*    // with length j that sums up to k*/
    /*    ll n = nums.size();*/
    /*    vector<vector<vector<ll>>> dp(n, vector<vector<ll>>(n+1, vector<ll>(k+1)));*/
    /**/
    /*    // dp[0][0][0] = 1, dp[0][1][a_0] = 1*/
    /*    for (ll i = 0; i < n; i++) dp[i][0][0] = 1;*/
    /*    if (nums[0] <= k) dp[0][1][nums[0]] = 1;*/
    /**/
    /*    for (ll i = 1; i < n; i++) {*/
    /*        for (ll j = 1; j <= n; j++) {*/
    /*            for (ll t = 1; t <= k; t++) {*/
    /*                dp[i][j][t] = dp[i-1][j][t];*/
    /*                if (nums[i] <= t) {*/
    /*                    dp[i][j][t] += dp[i-1][j-1][t-nums[i]];*/
    /*                }*/
    /*            }*/
    /*        }*/
    /*    }*/
    /**/
    /*    long long ans = 0;*/
    /*    for (ll j = 1; j <= n; j++) {*/
    /*        ans += (((__int128)1 << (n - j)) % mod * dp[n-1][j][k]) % mod;*/
    /*        ans %= mod;*/
    /*    }*/
    /**/
    /*    return ans;*/
    /*}*/
    int sumOfPower(vector<int>& nums, int k) {
        // dp[i][j] = power of the subsequences of a_0, ... , a_i with
        // sum j.
        // For subsequence T and its subsequences S, there are 3 cases for a_i:
        //  1. a_i is in T but not S: dp[i-1][j]
        //  2. a_i is not in T: dp[i-1][j]
        //  3. a_i is in T and S: dp[i-1][j-nums[i]]
    }
};
