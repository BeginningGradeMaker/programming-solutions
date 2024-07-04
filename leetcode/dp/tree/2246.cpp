class Solution {
    int ans = 0;
public:
    int longestPath(vector<int>& parent, string s) {
        int n = parent.size();
        vector<vector<int>> child(n);
        for (int i = 1; i < n; i++) {
            child[parent[i]].push_back(i);
        }
        // for (int i = 0; i < n; i++) {
        //     cout << i << ": ";
        //     for (int c : child[i]) {
        //         cout << c << ' ';
        //     }
        //     cout << endl;
        // }
        auto dfs = [&] (auto&& dfs, int i, char p) -> int {
            int fs = 0, sc = 0;
            for (int c : child[i]) {
                int l = dfs(dfs, c, s[i]);
                if (l >= fs) {
                    sc = fs;
                    fs = l;
                } else if (l > sc) {
                    sc = l;
                }
            }
            // cout << endl;
            // if (fs + sc == 3) cout << i << ": " << fs << ' ' << sc << endl;
            // if (i == 0) cout << fs << ' ' << sc << endl;
            ans = max(ans, fs + sc + 1);
            return s[i] == p ? 0 : fs + 1;
        };

        dfs(dfs, 0, ' ');
        return ans;
    }
};
