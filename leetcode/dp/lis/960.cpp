class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs[0].size();
        vector<int> dp(n, 1);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                bool ok = true;
                for (int k = 0; k < strs.size(); k++) {
                    if (strs[k][j] > strs[k][i]) {
                        ok = false;
                        break;
                    }
                }
                if (ok) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }

        return n - *max_element(dp.begin(), dp.end());
    }
};
