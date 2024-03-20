class Solution {
public:
  int minimumDeletions(string word, int k) {
    vector<int> v(26);

    for (char c : word) {
      v[c - 'a']++;
    }

    sort(v.begin(), v.end());

    int ans = INT_MAX;
    for (int i = 0; i < 26; i++) {
      int cnt = 0;
      int m = v[i];
      int t = m + k;
      for (int j = 0; j < 26; j++) {
        if (j >= i) {
          cnt += max(0, v[j] - t);
        } else {
          cnt += v[j]; 
        }
      }
      ans = min(ans , cnt);
    }

    return ans;
  }
};
