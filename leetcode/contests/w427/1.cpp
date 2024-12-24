class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);
        for (int i = 0; i < n; i++) {
            if (nums[i] > 0) {
                result[i] = nums[(i + nums[i]) % n];
            } else if (nums[i] < 0) {
                result[i] = nums[(i + n + nums[i] % n) % n];
            } else {
                result[i] = 0;
            }
        }

        return result;
    }
};
