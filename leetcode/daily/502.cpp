class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        auto byCap = [&] (int i, int j) {
            return capital[i] < capital[j];
        };
        auto byPro = [&] (int i, int j) {
            return profits[i] > profits[j];
        };
        multiset<int, decltype(byCap)> C(byCap);
        multiset<int, decltype(byPro)> P(byPro);

        for (int i = 0; i < n; i++) {
            C.insert(i);
        }

        for (int i = 0; i < k; i++) {
            while (!C.empty() && capital[*C.begin()] <= w) {
                int j = *C.begin();
                C.erase(C.begin());
                P.insert(j);
            }
            if (!P.empty()) {
                w += profits[*P.begin()];
                P.erase(P.begin());
            } else {
                return w;
            }
        }

        return w;
    }
};
