class Solution {
public:
    int closestCost(vector<int>& baseCosts, vector<int>& toppingCosts, int target) {
        // int mx = max(*max_element(toppingCosts.begin(), toppingCosts.end()), *max_element(baseCosts.begin(), baseCosts.end()));
        int price = 1e5;
        int n = baseCosts.size();
        int m = toppingCosts.size();
        vector<vector<int>> dp(vector<vector<int>>(m * 2, vector<int>(price + 1, 0)));

        for (int i = 0; i < m; i++) {
            toppingCosts.push_back(toppingCosts[i]);
        }

        dp[0][0] = 1;
        if (toppingCosts[0] <= price) {
            dp[0][toppingCosts[0]] = 1;
        }

        // dp[i][j] = true if there exists some subset of a_i, ... , a_j that
        // sum up to exactly j.
        // cout << "haha" << endl;
        for (int i = 1; i < m * 2; i++) {
            for (int j = 0; j <= price; j++) {
                if (toppingCosts[i] <= j) {
                    dp[i][j] = dp[i-1][j - toppingCosts[i]];
                }
                dp[i][j] = max(dp[i][j], dp[i-1][j]);
            }
        }

        int ans = INT_MAX;

        // for (int i = 0; i < m * 2; i++) {
        //     for (int j = 0; j <= price; j++) {
        //         cout << dp[i][j] << ' ';
        //     }
        //     cout << endl;
        // }

        for (int i = 0; i < n; i++) {
            for (int k = 0; k <= price; k++) {
                if (dp[2*m - 1][k] == 1) {
                    if (abs(k + baseCosts[i] - target) < abs(ans - target) || 
                        (abs(k + baseCosts[i] - target) == abs(ans - target) &&
                        k + baseCosts[i] < ans)) {
                        ans = k + baseCosts[i];
                    }
                }
            }
        }

        return ans;
    }
};
