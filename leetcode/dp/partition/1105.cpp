class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        int n = books.size();
        vector<int> dp(n, INT_MAX);
        dp[0] = books[0][1];
        for (int i = 1; i < n; i++) {
            int width = 0;
            int height = 0;
            for (int j = i; j >= 0; j--) {
                width += books[j][0];
                height = max(height, books[j][1]);
                if (width > shelfWidth) {
                    break;
                }
                dp[i] = min((j > 0 ? dp[j-1] : 0) + height, dp[i]);
            }
        }

        return dp[n-1];
    }
};
