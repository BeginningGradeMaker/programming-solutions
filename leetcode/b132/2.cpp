class Solution {
public:
    int findWinningPlayer(vector<int>& skills, int k) {
        int n = skills.size();
        if (k >= n) return max_element(skills.begin(), skills.end()) - skills.begin();


        int cnt = 0;
        int cur = -1;
        deque<int> arr(n);
        iota(arr.begin(), arr.end(), 0);

        while (cnt < k) {
            int first = arr.front();
            arr.pop_front();
            int nxt = arr.front();

            if (skills[first] > skills[nxt]) {
                arr.pop_front();
                arr.push_back(nxt);
                arr.push_front(first);
                if (cur == first) {
                    cnt++;
                } else {
                    cnt = 1;
                    cur = first;
                }
            } else {
                arr.push_back(first);
                if (cur == nxt) {
                    cnt++;
                } else {
                    cnt = 1;
                    cur = nxt;
                }
            }
        }

        return cur;
    }
};
