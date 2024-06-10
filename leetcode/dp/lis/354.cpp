class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), [&] (vector<int> v1, vector<int> v2) {
            if (v1[0] == v2[0]) {
                return v1[1] > v2[1];
            }

            return v1[0] < v2[0];
        });

        int n = envelopes.size();
        vector<int> dp(n+1, INT_MAX);
        dp[0] = INT_MIN;

        for (int i = 0; i < n; i++) {
            int j = upper_bound(dp.begin(), dp.end(), envelopes[i][1]) - dp.begin();

            if (envelopes[i][1] > dp[j-1] && envelopes[i][1] < dp[j]) {
                dp[j] = envelopes[i][1];
            }
        }

        for (int i = n; i >= 0; i--) {
            if (dp[i] < INT_MAX) return i;
        }

        return 0;
    }
};
