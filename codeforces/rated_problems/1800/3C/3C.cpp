#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int INF = 0x3f3f3f3f;
int mod = 1e9 + 7;
int N = 200005;

void solve() {
    // Solution goes here
    vector<vector<char>> board(3, vector<char>(3));
    int c1 = 0, c2 = 0;
    for (int i = 0; i < 3; i++) {
        string s; cin >> s;
        for (int j = 0; j < 3; j++) {
            if (s[j] == 'X') c1++;
            else if (s[j] == '0') c2++;
            board[i][j] = s[j];
        }
    }

    if (c1 != c2 + 1 && c1 != c2) {
        cout << "illegal" << endl;
        return;
    }

    vector<int> row(3);
    vector<int> col(3);
    vector<int> diag(2);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == 'X') row[i]++;
            else if (board[i][j] == '0') row[i]--;
            if (board[j][i] == 'X') col[i]++;
            else if (board[j][i] == '0') col[i]--;
        }

        if (board[i][i] == 'X') diag[0]++;
        else if (board[i][i] == '0') diag[0]--;
        if (board[i][2-i] == 'X') diag[1]++;
        else if (board[i][2-i] == '0') diag[1]--;
    }

    int cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < 3; i++) {
        cnt1 += row[i] == 3;
        cnt2 += row[i] == -3;
        cnt1 += col[i] == 3;
        cnt2 += col[i] == -3;
    }
    if (diag[0] == 3) cnt1++;
    else if (diag[0] == -3) cnt2++;
    if (diag[1] == 3) cnt1++;
    else if (diag[1] == -3) cnt2++;

    if (cnt1 && cnt2) {
        cout << "illegal" << endl;
    } else if (!cnt1 && !cnt2) {
        if (c1 + c2 == 9) {
            cout << "draw" << endl;
        } else if (c1 > c2) {
            cout << "second" << endl;
        } else {
            cout << "first" << endl;
        }
    } else if (cnt1) {
        if (c1 == c2 || cnt1 == 2 && ((row[0] == 3 && row[2] == 3) || (col[0] == 3 && col[2] == 3))) {
            cout << "illegal" << endl;
        } else {
            cout << "the first player won" << endl;
        }
    } else {
        if (c1 > c2 || cnt2 == 2 && ((row[0] == -3 && row[2] == -3) || (col[0] == -3 && col[2] == -3))) {
            cout << "illegal" << endl;
        } else {
            cout << "the second player won" << endl;
        }
    }

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // Input handling goes here
    solve();
}
