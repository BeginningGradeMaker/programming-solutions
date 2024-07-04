#include <numeric>
class Solution {
public:
  vector<int> deckRevealedIncreasing(vector<int> &deck) {
    int n = deck.size();
    queue<int> q;
    vector<int> pos(n);

    for (int i = 0; i < n; i++) q.push(i);
    for (int i = 0; i < n; i++) {
      pos[i] = q.front();
      q.pop();
      q.push(q.front());
      q.pop();
    }
    sort(deck.begin(), deck.end());
    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
      ans[pos[i]] = deck[i];
    }

    return ans;
  }
};
