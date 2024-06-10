#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int INF = 0x3f3f3f3f;
int mod = 1e9 + 7;
int N = 200005;

void solve() {
    // Solution goes here
    int N; cin >> N;
    string b; cin >> b;
    set<char> S;
    vector<char> D;
    
    for (char c : b) {
        S.insert(c);
    }

    for (char c : S) {
        D.push_back(c);
    }

    map<char, char> M;
    int n = D.size();
    for (int i = 0; i <= n / 2; i++) {
        M[D[i]] = D[n - 1 - i];
        M[D[n - 1 - i]] = D[i];
    }

    for (char &c : b) {
        c = M[c];
    }

    cout << b << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // Input handling goes here
    int t; cin >> t;
    while (t--) {
        solve();
    }
}
