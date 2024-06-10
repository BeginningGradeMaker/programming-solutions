#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int INF = 0x3f3f3f3f;
int mod = 1e9 + 7;
int N = 200005;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // Input handling goes here

    int N; cin >> N;

    int first; cin >> first;

    for (int i = 1; i < N; i++) {
        int x; cin >> x;
        if (x > first) {
            cout << i + 1 << endl;
            return 0;
        }
    }

    cout << -1 << endl;
}
