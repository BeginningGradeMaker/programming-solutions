#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int mod = 1000000007;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // solution goes here
    int x, n;
    cin >> x >> n;
    auto compare = [] (const pair<int, int> &p1, const pair<int, int> &p2) {
        int n1 = p1.second - p1.first + 1;
        int n2 = p2.second - p2.first + 1;
        return n1 == n2 ? p1 < p2 : n1 > n2; 
    };
    set<pair<int, int>, decltype(compare)> st(compare);
    map<int, int> mp;
    mp[x] = 0;

    for (int i = 0; i < n; i++) {
        int k; cin >> k;
        auto it = mp.upper_bound(k);
        int a = it->second, b = it->first;
        mp[b] = k;
        mp[k] = a;
        st.erase({a, b});
        st.insert({k, b});
        st.insert({a, k});
        cout << st.begin()->second - st.begin()->first << ' ';
        // cout << st.begin()->first << ' ' << st.begin()->second << endl;
    }
    cout << endl;
}
