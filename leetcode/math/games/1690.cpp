class Solution {
public:
    int stoneGameVII(vector<int>& stones) {
        // dp[l, r] = point + dp[l+1, r]
        int n = stones.size();
        vector<vector<int>> sum(n, vector<int>(n));
        vector<vector<int>> dp(n, vector<int>(n));
        for (int i = 0; i < n; i++) {
            int tmp = 0;
            for (int j = i; j < n; j++) {
                tmp += stones[j];
                sum[i][j] = tmp;
            }
        }
        /*for (int i = 0; i < n; i++) {*/
        /*    for (int j = 0; j < n; j++) {*/
        /*        cout << sum[i][j] << ' ';*/
        /*    }*/
        /*    cout << endl;*/
        /*}*/

        for (int len = 2; len <= n; len++) {
            for (int i = 0; i <= n - len; i++) {
                dp[i][i+len-1] = max(sum[i+1][i+len-1] - dp[i+1][i+len-1], sum[i][i+len-2] - dp[i][i+len-2]);
            }
        }

        /*for (int i = 0; i < n; i++) {*/
        /*    for (int j = 0; j < n; j++) {*/
        /*        cout << "dp(" << i << ", " << j << "): " << dp[i][j] << "   ,";*/
        /*    }*/
        /*    cout << endl;*/
        /*}*/
        return dp[0][n-1];
    }
};
