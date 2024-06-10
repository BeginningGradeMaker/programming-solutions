#include <bits/stdc++.h>
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
    int N, X, Y, Z; cin >> N >> X >> Y >> Z;
    cout << ((max(X, Y) >= Z && min(X, Y) <= Z) ? "Yes" : "No") << endl;
}
