class Solution {
public:
    int maxHeight(vector<vector<int>>& cuboids) {
        int n = cuboids.size();
        vector<int> dp(n);
        for (int i = 0; i < n; i++) {
            sort(cuboids[i].begin(), cuboids[i].end());
        }
        sort(cuboids.begin(), cuboids.end());
        for (int i = 0; i < n; i++) {
            dp[i] = cuboids[i][2];
        }

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (cuboids[j][1] <= cuboids[i][1] &&
                    cuboids[j][2] <= cuboids[i][2] ) {
                    dp[i] = max(dp[i], dp[j] + cuboids[i][2]);
                }
            }
        }

        return *max_element(dp.begin(), dp.end());
    }
};
