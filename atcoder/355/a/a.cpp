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
    int A, B; cin >> A >> B;
    set<int> S{1, 2, 3};
    S.erase(A);
    S.erase(B);

    if (S.size() == 2) {
        cout << -1 << endl;
    } else {
        cout << *S.begin() << endl;
    }
}
