class Solution {
public:
    int numberOfChild(int n, int k) {
        int dir = 1;
        int cur = 0;
        while (k--) {
            cur += dir;
            if (cur == n-1) {
                dir = -1;
            } else if (cur == 0) {
                dir = 1;
            }
        }
        
        return cur;
    }
};
