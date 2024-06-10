class Solution {
public:
    int tallestBillboard(vector<int>& rods) {
        int n = rods.size();
        int sum = accumulate(rods.begin(), rods.end(), 0);
        // dp[i][k] = the largest sum of two steel supports that
        // the difference is k.
        unordered_map<int, unordered_map<int, int>> dp;

        dp[0][rods[0]] = rods[0];
        dp[0][-rods[0]] = rods[0];

        for (int i = 1; i < n; i++) {
            for (int k = -sum; k <= sum; k++) {
                // if rods[i] is on the shorter steel, then
                // dp[i-1][k+rods[i]]
                // if rods[i] is on the larger steel, then
                // dp[i-1][rods[i]-d] or dp[i-1][d-rods[i]]
                dp[i][k] = dp[i-1][k];
                dp[i][k] = max(dp[i][k], max(dp[i-1][k+rods[i]], dp[i-1][abs(k-rods[i])]) + rods[i]);
            }
        }

        return dp[n-1][0] / 2;
    }
};
