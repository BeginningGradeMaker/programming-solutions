class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int> dp(n+2);
        dp[n-1] = stoneValue[n-1];
        for (int i = n - 2; i >= 0; i--) {
            dp[i] = stoneValue[i] - dp[i+1];
            dp[i] = max(dp[i], stoneValue[i] + stoneValue[i+1] - dp[i+2]);
            if (i + 2 < n) dp[i] = max(dp[i], stoneValue[i] + stoneValue[i+1] + stoneValue[i+2] - dp[i+3]);
        }

        for (int i = 0; i < n; i++) {
            cout << dp[i] << ' ';
        }
        cout << endl;

        if (dp[0] > 0) return "Alice";
        else if (dp[0] < 0) return "Bob";
        else return "Tie";
    }
};
