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
    string S, T; cin >> S >> T;
    int i = 0, j = 0;
    int n = S.size();
    while (i < n) {
        if (S[i] == T[j]) {
            cout << j+1 << ' ';
            i++; j++;
        } else {
            j++;
        }
    }
}
