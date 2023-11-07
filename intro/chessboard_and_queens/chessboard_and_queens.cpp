#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int mod = 1000000007;

int ans = 0;

void dfs(int row, vector<vector<bool>> &board, vector<bool> &vertical, vector<bool> &diagonal, vector<bool> &rev_diagonal) {
    if (row == 8) {
        ans++;
        return;
    }

    for (int col = 0; col < 8; col++) {
        if (board[row][col] && vertical[col] && diagonal[row+col] && rev_diagonal[7 - col + row]) {
            vertical[col] = false;
            diagonal[row+col] = false;
            rev_diagonal[7 - col + row] = false;
            dfs(row+1, board, vertical, diagonal, rev_diagonal);
            vertical[col] = true;
            diagonal[row+col] = true;
            rev_diagonal[7 - col + row] = true;
        }
    }
}

int main() {
    // solution goes here
    vector<vector<bool>> board(8, vector<bool>(8));

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            char c; cin >> c;
            board[i][j] = c == '.';
        }
    }

    vector<bool> vertical(8, true);
    vector<bool> diagonal(15, true);
    vector<bool> rev_diagonal(15, true);
    dfs(0, board, vertical, diagonal, rev_diagonal);

    cout << ans << endl;
}
