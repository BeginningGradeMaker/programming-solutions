class Solution {
public:
    int maxTotalReward(vector<int>& rewardValues) {
        int n = rewardValues.size();
        vector<int> dp(n);
        sort(rewardValues.begin(), rewardValues.end());
        dp[0] = rewardValues[0];

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (dp[j] < rewardValues[i]) {
                    dp[i] = max(dp[i], dp[j] + rewardValues[i]);
                }
            }
        }

        return *max_element(dp.begin(), dp.end());
    }
};
