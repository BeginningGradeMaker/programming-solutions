class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(k+1));
        dp[0][0] = 1;

        for (int i = 1; i < n; i++) {
            dp[i][0] = 1;
            for (int j = 0; j < i; j++) {
                for (int t = 0; t <= k; t++) {
                    if (nums[j] != nums[i] && t != 0) {
                        dp[i][t] = max(dp[i][t], dp[j][t-1] + 1);
                    } else if (nums[j] == nums[i]) {
                        dp[i][t] = max(dp[i][t], dp[j][t] + 1);
                    }
                }
            }
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= k; j++) {
                ans = max(ans, dp[i][j]);
            }
        }

        return ans;
    }
};
