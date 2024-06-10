class Solution {
public:
    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        vector<vector<int>> dp(nums.size(), vector<int>(target + 1));
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            dp[i][0] = 0;
        }
        for (int i = 1; i <= target; i++) {
            dp[0][i] = i == nums[0] ? 1 : -1;
        }

        // dp[i][j] = max(dp[i-1][target - nums[i]] + 1, dp[i-1][target])
        for (int i = 1; i < n; i++) {
            for (int j = 1; j <= target; j++) {
                if (j >= nums[i] && dp[i-1][j - nums[i]] >= 0) {
                    dp[i][j] = max(dp[i-1][j - nums[i]] + 1, dp[i-1][j]);
                } else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }

        return dp[n-1][target];
    }
};
