class Solution {
public:
  int numSubarrayProductLessThanK(vector<int> &nums, int k) {
    int cnt = 0;

    int i = 0;
    int cur = 1;
    for (int j = 0; j < nums.size(); j++) {
      cur *= nums[j];
      while (i < j && cur >= k) {
        cur /= nums[i++];
      }
      if (cur < k) {
        cnt += j - i + 1;
      }
    }

    return cnt;
  }
};
