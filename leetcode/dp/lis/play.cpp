class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, vector<int>> dp;
        for (int x : nums) {
            if (dp.find(x) == dp.end()) {
                dp[x] = vector<int>(k+1);
            }
        }
        vector<map<int, int>> S(k+1);
        dp[nums[0]][0] = 1;
        S[0][1]++;
        

        for (int i = 1; i < n; i++) {
            for (int t = 0; t <= k; t++) {
                S[t][dp[nums[i]][t]]--;
                dp[nums[i]][t] += 1;
                S[t][dp[nums[i]][t]]++;
                if (t != 0) {
                    S[t-1][dp[nums[i]][t-1]]--;
                    if (S[t-1][dp[nums[i]][t-1]] == 0) {
                        S[t-1].erase(dp[nums[i]][t-1]);
                    }
                    if (S[t-1].empty() == false)
                    dp[nums[i]][t] = max(dp[nums[i]][t], max_element(S[t-1].begin(), S[t-1].end())->first);
                    S[t-1][dp[nums[i]][t-1]]++;
                }
            }
        }

        int ans = 0;
        for (int x : nums) {
            for (int j = 0; j <= k; j++) {
                ans = max(ans, dp[x][j]);
            }
        }

        return ans;
    }
};
