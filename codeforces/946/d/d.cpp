#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int INF = 0x3f3f3f3f;
int mod = 1e9 + 7;
int N = 200005;

void solve() {
    // Solution goes here
    int n; cin >> n;
    string s; cin >> s;

    int x = 0, y = 0;
    for (char c : s) {
        if (c == 'E') x++;
        else if (c == 'W') x--;
        else if (c == 'N') y++;
        else y--;
    }

    // If x % 2 = 1, then no matter how we assign x1, x2
    // to R, H, respectively, we would have abs(x1 - x2) > 0
    // so R and H cannot have same x-coordinate. Same with y
    if (x % 2 != 0 || y % 2 != 0) {
        cout << "NO" << endl;
        return;
    }

    // n is even
    if (x == 0 && y == 0 && n == 2) {
        // s must be one of EW, WE, SN, NS, so only one of
        // R, H can move
        cout << "NO" << endl;
        return;
    }

    if (x == 0 && y == 0 && n > 2 ) {
        // we can assign first move and its complement to R
        // and rest to H. Both will end at (0, 0)
        char m = s[0];
        s[0] = 'R';
        for (int i = 1; i < n; i++) {
            if (m == 'E' && s[i] == 'W' || m == 'W' && s[i] == 'E' ||
                m == 'N' && s[i] == 'S' || m == 'S' && s[i] == 'N') {
                s[i] = 'R';
                m = ' ';
            } else {
                s[i] = 'H';
            }
        }
    } else {
        // for all other cases we can assign x/2 and y/2 of moves 
        // in the direction of the sign of x and y to R, and assign
        // the rest to H
        int cnt1 = 0, cnt2 = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == 'E' && x > 0 && cnt1 < x / 2 ||
                s[i] == 'W' && x < 0 && cnt1 < abs(x / 2)) {
                s[i] = 'R';
                cnt1++;
            } else if (s[i] == 'N' && y > 0 && cnt2 < y / 2 ||
                       s[i] == 'S' && y < 0 && cnt2 < abs(y / 2)) {
                s[i] = 'R'; 
                cnt2++;
            } else {
                s[i] = 'H';
            }
        }
    }

    cout << s << endl;
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
