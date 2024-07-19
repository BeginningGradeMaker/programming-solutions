class Solution {
public:
  int longestMonotonicSubarray(vector<int> &nums) {
    int ans = 1;
    int n = nums.size();

    for (int i = 0; i < nums.size(); i++) {
      int j;
      for (j = i; j < nums.size() - 1; j++) {
        if (nums[j+1] <= nums[j]) {
          break;
        }
      }
      ans = max(ans, j - i + 1);
    }
    
    for (int i = 0; i < nums.size(); i++){
      int j;
      for (j = i; j < nums.size() - 1; j++) {
        if (nums[j+1] >= nums[j]) {
          break;
        }
      }
      ans = max(ans, j - i + 1);
    }

    return ans;
  }
};
