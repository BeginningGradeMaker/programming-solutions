class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int sum = accumulate(stones.begin(), stones.end(), 0);
        int n = stones.size();
        unordered_map<int, unordered_map<int, int>> dp;

        // dp[i][j] = dp[i][j - stones[i]] + dp[i][j + stones[i]]
        dp[0][stones[0]] += 1;
        dp[0][-stones[0]] += 1;

        for (int i = 1; i < n; i++) {
            for (int j = -sum; j <= sum; j++) {
                if (dp[i-1].count(j - stones[i])) {
                    dp[i][j] += dp[i-1][j - stones[i]];
                }
                if (dp[i-1].count(j + stones[i])) {
                    dp[i][j] += dp[i-1][j + stones[i]];
                }
            }
        }

        for (int i = 0; i <= target; i++) {
            if (dp[n-1][i] > 0) return i;
        }

        return 0;
    }
};
