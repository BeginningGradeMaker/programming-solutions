class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors) {
        int n = colors.size();
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (colors[i%n] != colors[(i+1)%n] && colors[(i+1)%n] != colors[(i+2)%n]) {
                cnt++;
            }
        }

        return cnt;
    }
};
