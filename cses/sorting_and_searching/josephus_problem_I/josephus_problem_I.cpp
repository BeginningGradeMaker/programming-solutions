#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int mod = 1000000007;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // solution goes here
    int n; cin >> n;
    deque<int> ans(n);
    iota(ans.begin(), ans.end(), 1);

    while (ans.size() > 1) {
        deque<int> tmp;
        int k = ans.size();
        for (int i = 0; i < k; ++i) {
            if (i % 2 == 0) {
                if (i == k - 1) {
                    tmp.push_front(ans[i]);
                } else {
                    tmp.emplace_back(ans[i]);
                }
            } else {
                cout << ans[i] << ' ';
            }
        }
        ans = std::move(tmp);
    }

    cout << ans[0] <<  endl;
}
