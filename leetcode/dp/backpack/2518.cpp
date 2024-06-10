typedef long long ll;
class Solution {
    ll mod = 1e9 + 7;
public:
    int countPartitions(vector<int>& nums, int k) {
        // dp[i][k] = number of partitions of a_0 ... a_i that sums up to
        // exactly k.
        ll n = nums.size();
        vector<vector<ll>> dp(n, vector<ll>(k));

        ll sum = 0;
        ll ok = false;
        for (ll x : nums) {
            sum += x;
            if (sum >= 2 * k) {
                ok = true;
                break;
            }
        }

        if (!ok) return 0;

        dp[0][0] = 1;
        if (nums[0] < k) dp[0][nums[0]] = 1;

        for (ll i = 1; i < n; i++) {
            for (ll j = 0; j < k; j++) {
                dp[i][j] = dp[i-1][j];
                if (nums[i] <= j) dp[i][j] += dp[i-1][j - nums[i]];
            }
        }

        ll bad = 0;
        for (ll i = 0; i < k; i++) {
            cout << dp[n-1][i] << ' ';
            bad += dp[n-1][i];
            bad %= mod;
        }
        cout << endl;
        bad *= 2;
        bad %= mod;

        ll total = 1;
        for (ll i = 0; i < n; i++) {
            total *= 2;
            total %= mod;
        }

        if (total < bad) total += mod;
        return (total - bad) % mod;
    }
};
