class Solution {
public:
  string getSmallestString(string s, int k) {
    string t = "";

    for (auto c : s) {
      for (char i = 'a'; i <= 'z'; i++) {
        int d = min(abs(i - c), min(c, i) + 26 - max(c, i));
        if (d <= k) {
          t.push_back(i);
          k -= d;
          break;
        }
      }
    }

    return t;
  }
};
