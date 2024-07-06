class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int n = colors.size();
        int cnt = 0;
        int i = 0;
        for (int j = 1; j < n + k - 1; j++) {
            if (colors[j%n] != colors[(j-1)%n]) continue;

            if (j - i + 1 >= k) {
                cnt += (j - i + 1) - k;
                cout << i << ' ' << j << ' ' << cnt << endl;
            }
            i = j;
        }

        return cnt;
    }
};
