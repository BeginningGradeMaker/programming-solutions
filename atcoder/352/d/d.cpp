#include <algorithm>
#include <bits/stdc++.h>
#include <numeric>
#include <type_traits>
#include <vector>
using namespace std;
typedef long long ll;
int INF = 0x3f3f3f3f;
int mod = 1e9 + 7;
int N = 200005;

void solve() {
    // Solution goes here
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // Input handling goes here
    int N, K; cin >> N >> K;
    vector<int> P(N);

    for (int &x : P) cin >> x;
    

    vector<int> idx(N);
    iota(idx.begin(), idx.end(), 0);
    sort(idx.begin(), idx.end(), [&] (int i, int j) { return P[i] < P[j]; });

    set<int> st;
    for (int i = 0; i < K; i++) {
        st.insert(idx[i]);
    }
    // for (int i : st) {
    //     cout << P[i] << ' ';
    // }
    // cout << endl;
    
    int ans = *st.rbegin() - *st.begin();
    for (int i = K; i < N; i++) {
        st.erase(idx[i - K]);
        st.insert(idx[i]);
        ans = min(ans, *st.rbegin() - *st.begin());
        // for (int i : st) {
        //     cout << P[i] << ' ';
        // }
        // cout << endl;
    }

    cout << ans << endl;
}
