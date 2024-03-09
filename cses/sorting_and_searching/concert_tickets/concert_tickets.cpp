#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int mod = 1000000007;

int main() {
    // solution goes here
    int n, m;
    cin >> n >> m;
    multiset<int> tk;
    for (int i = 0; i < n; i++) {
        int t; cin >> t;
        tk.insert(t);
    }

    vector<int> pr(m);
    for (int i = 0; i < m; i++) {
        cin >> pr[i];
    }

    for (int i = 0; i < m; i++) {
        auto it = tk.upper_bound(pr[i]);
        if (it != tk.begin()) {
            it--;
            cout << *it << endl;
            tk.erase(it);
        } else {
            cout << -1 << endl;
        }
    }
}
