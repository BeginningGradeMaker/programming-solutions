typedef long long ll;
class Solution {
public:
    int paintWalls(vector<int>& cost, vector<int>& time) {
        // NOTE: 
        // sum of paid painter's time units >= # of times free painter paint
        // # of times free painter paint + # of times paid painters paint = n
        // =>
        // sum of paid painter's time units >= n - # of times paid painters paint
        // sum of (paint time unit + 1) >= n
        // 
        // dp[i][j] = the minimum cost in a_0 ... a_i such that the sum of paint
        // time units + 1 is at least n
        int n = cost.size();
        for (int &x : time) x++;
        vector<vector<ll>> dp(n, vector<ll>(n+1, INT_MAX));

        for (int i = 0; i < min(n, time[0]); i++) {
            dp[0][i+1] = cost[0];
        }
        dp[0][0] = 0;

        for (int i = 1; i < n; i++) {
            for (int j = 0; j <= n; j++) {
                dp[i][j] = min(dp[i-1][j], dp[i-1][max(0, j - time[i])] + cost[i]);
            }
        }

        // for (int i = 0; i < n; i++) {
        //     for (int j = 0; j <= n; j++) {
        //         cout << dp[i][j] << ' ';
        //     }
        //     cout << endl;
        // }

        return dp[n-1][n];
    }
};

