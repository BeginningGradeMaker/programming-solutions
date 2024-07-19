class Solution {
public:
    int stoneGameVI(vector<int>& a, vector<int>& b) {
        int n = a.size();
        int sum1 = 0, sum2 = 0;
        vector<int> idx(n);
        iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(), [&] (int i, int j) {
            return a[i] + b[i] > a[j] + b[j];
        });

        for (int i = 0; i < n; i++) {
            if (!(i & 1)) {
                sum1 += a[idx[i]];
            } else {
                sum2 += b[idx[i]];
            }
        }

        if (sum1 > sum2) return 1;
        else if (sum1 < sum2) return -1;
        else return 0;
    }
};
