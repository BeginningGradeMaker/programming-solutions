class Solution {
    int mod = 1e9 + 7;
public:
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        int m = profit.size();
        vector<vector<vector<int>>> dp(m+1, vector<vector<int>>(n+1, vector<int>(minProfit+1, 0)));

        // dp[i][j][k] = the number of subsets of a_0, ... , a_i that has max of j people
        // and with at least k profit
        for (int j = 0; j <= n; j++) {
            for (int k = 0; k <= minProfit; k++) {
                dp[0][j][k] = (group[0] <= j && profit[0] >= k) ? 1 : 0;
                if (k == 0) {
                    dp[0][j][k]++;
                }
            }
        }
        // for (int j = 0; j <= n; j++) {
        //     dp[0][j][0] = 1;
        // }

        for (int i = 1; i < m; i++) {
            for (int j = 0; j <= n; j++) {
                for (int k = 0; k <= minProfit; k++) {
                    dp[i][j][k] += dp[i-1][j][k];
                    if (group[i] <= j) {
                        dp[i][j][k] += dp[i-1][j - group[i]][max(0, k - profit[i])];
                        dp[i][j][k] %= mod; 
                    }
                }
            }
        }

        return dp[m-1][n][minProfit];
    }
};
