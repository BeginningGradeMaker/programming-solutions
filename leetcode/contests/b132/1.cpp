class Solution {
public:
    string clearDigits(string s) {
        int n = s.size();
        vector<int> d(n);
        
        for (int i = 0; i < n; i++) {
            if (isdigit(s[i])) {
                d[i] = 1;
                for (int j = i-1; j >= 0; j--) {
                    if (!isdigit(s[j]) && !d[j]) {
                        d[j] = 1;
                        break;
                    }
                }
            }
        }
        
        string ans = "";
        for (int i = 0; i < n; i++) {
            if (!d[i]) ans += s[i];
        }
        
        return ans;
    }
};
