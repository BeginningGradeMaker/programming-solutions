class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int n = scores.size();
        vector<int> idx(n);
        iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(), [&] (int i, int j) {
            return ages[i] < ages[j];
        });

        // dp[i] = the highest score ending at a[i]
        vector<int> dp(n);
        for (int i : idx) {
            dp[i] = scores[i];
        }

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (ages[idx[i]] == ages[idx[j]]) {
                    dp[idx[i]] = max(dp[idx[i]], dp[idx[j]] + scores[idx[i]]);
                } else if (scores[idx[j]] <= scores[idx[i]]) {
                    dp[idx[i]] = max(dp[idx[i]], dp[idx[j]] + scores[idx[i]]);
                }
            }
        }

        return *max_element(dp.begin(), dp.end());
    }
};
