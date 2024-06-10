class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int n = nums.size();
        unordered_map<int, unordered_map<int, int>> dp;

        // dp[i][j] = dp[i][j - nums[i]] + dp[i][j + nums[i]]
        dp[0][nums[0]] += 1;
        dp[0][-nums[0]] += 1;

        for (int i = 1; i < n; i++) {
            for (int j = -sum; j <= sum; j++) {
                if (dp[i-1].count(j - nums[i])) {
                    dp[i][j] += dp[i-1][j - nums[i]];
                }
                if (dp[i-1].count(j + nums[i])) {
                    dp[i][j] += dp[i-1][j + nums[i]];
                }
            }
        }

        return dp[n-1][target];
    }
};
