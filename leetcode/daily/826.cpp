class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n = difficulty.size();
        vector<int> idx(n);
        iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(), [&] (int i, int j) {
            return profit[i] > profit[j];
        });
        sort(worker.begin(), worker.end(), greater<int>());

        int ans = 0;
        int j = 0;
        for (int i = 0; i < worker.size(); i++) {
            while (j < n && worker[i] < difficulty[idx[j]]) j++;
            if (j < n) {
                ans += profit[idx[j]];
            }
        }

        return ans;
    }
};
