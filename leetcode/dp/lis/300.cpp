class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1, INT_MAX);
        dp[0] = INT_MIN;

        for (int i = 0; i < n; i++) {
            int j = upper_bound(dp.begin(), dp.end(), nums[i]) - dp.begin();

            if (nums[i] > dp[j-1] && nums[i] < dp[j]) {
                dp[j] = nums[i];
            }
        }

        for (int i = n; i >= 0; i--) {
            if (dp[i] < INT_MAX) {
                return i;
            }
        }

        return 0;
    }
};
