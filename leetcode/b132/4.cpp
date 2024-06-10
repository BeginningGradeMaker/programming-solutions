class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int n = nums.size();
        // dp[x][j] = the length longest subsquence ending at x with at most j differences
        unordered_map<int, vector<int>> dp;
        for (int x : nums) {
            dp[x].resize(k+1);
        }
        vector<int> M(k+1);

        for (int x : nums) {
            for (int t = k; t >= 0; t--) {
                dp[x][t]++;
                if (t > 0) {
                    dp[x][t] = max(dp[x][t], M[t-1] + 1);
                }
                M[t] = max(M[t], dp[x][t]);
            }
        }

        return M[k];
    }
};
