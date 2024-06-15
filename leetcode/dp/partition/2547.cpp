class Solution {
public:
    int minCost(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> dp(n, INT_MAX);
        dp[0] = k;

        for (int i = 1; i < n; i++) {
            map<int, int> cnt;
            int sum = 0;
            for (int j = i; j >= 0; j--) {
                int x = nums[j];
                cnt[x]++;
                if (cnt[x] == 2) {
                    sum += 2;
                } else if (cnt[x] > 2) {
                    sum++;
                }
                dp[i] = min(dp[i], (j > 0 ? dp[j-1] : 0) + sum + k);
            }
        }

        return dp[n-1];
    }
};
