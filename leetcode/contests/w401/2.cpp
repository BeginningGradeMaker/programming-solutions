class Solution {
    int mod = 1e9 + 7;
public:
    int valueAfterKSeconds(int n, int k) {
        vector<int> nums(n, 1);
        for (int i = 0; i < k; i++) {
            for (int j = 1; j < n; j++) {
                nums[j] += nums[j-1];
                nums[j] %= mod;
            }
        }

        return nums[n-1];
    }
};
