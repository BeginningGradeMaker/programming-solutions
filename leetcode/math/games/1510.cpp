class Solution {
public:
    bool winnerSquareGame(int n) {
        vector<int> ps;
        int num = 1;
        while (num * num <= n) {
            ps.push_back(num * num);
            num++;
        }
        vector<bool> dp(n+1, false);
        for (int i = 1; i <= n; i++) {
            for (int p : ps) {
                if (p > i) break;
                if (!dp[i - p]) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[n];
    }
};
