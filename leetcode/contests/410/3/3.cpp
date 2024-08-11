class Solution {
public:
    int countOfPairs(vector<int>& nums) {
        int mod = 1e9 + 7;
        int n = nums.size();
        // dp[i][j] = the number of good integer arrays with nums[i]
        // exactly j using numbers up to nums[i]
        // = dp[i-1][]
        vector<vector<int>> dp(n, vector<int>(51));
        for (int x = 0; x <= nums[0]; x++) {
            dp[0][x] = 1;
        }

        for (int i = 1; i < n; i++) {
            for (int x = 0; x <= nums[i]; x++) {
                for (int y = 0; y <= nums[i-1]; y++) {
                    if (x >= y && (nums[i] - x) <= (nums[i-1] - y)) {
                        dp[i][x] += dp[i-1][y];
                        dp[i][x] %= mod;
                    }
                }
            }
        }

        long long ans = 0;
        for (long long x : dp[n-1]) {
            ans += x;
            ans %= mod;
        }
        return ans;
    }
};
