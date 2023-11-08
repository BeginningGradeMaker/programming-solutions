#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int mod = 1000000007;

int ans = 0;
string mp;
vector<vector<bool>> visited(7, vector<bool>(7, false));

void dfs(int row, int col, int step) {
    if (row == 6 && col == 0) {
        if (step == 48) ans++;
        return;
    }
    if ((((row == 6 || visited[row+1][col]) && (row == 0 || visited[row-1][col])) && (col + 1 < 7 && !visited[row][col+1]) && 
        (col - 1 >= 0 && !visited[row][col-1])) || 
        (((col == 6 || visited[row][col+1]) && (col == 0 || visited[row][col-1])) && row + 1 < 7 && !visited[row+1][col] && 
        row - 1 >= 0 && !visited[row-1][col])) {
            return;
    }

    visited[row][col] = true;

    if (mp[step] != '?') {
        // this step is determined
        int i = row, j = col;
        switch (mp[step]) {
            case 'D':
                i++;
                break;
            case 'U':
                i--;
                break;
            case 'L':
                j--;
                break;
            case 'R':
                j++;
                break;
        }

        if (i >= 0 && j >= 0 && i < 7 && j < 7 && !visited[i][j]) {
            dfs(i, j, step+1);
        }
    } else {
        if (row+1 < 7 && !visited[row+1][col]) {
            dfs(row+1, col, step+1);
        }

        if (row-1 >= 0 && !visited[row-1][col]) {
            dfs(row-1, col, step+1);
        }

        if (col+1 < 7 && !visited[row][col+1]) {
            dfs(row, col+1, step+1);
        }

        if (col-1 >= 0 && !visited[row][col-1]) {
            dfs(row, col-1, step+1);
        }
    }

    visited[row][col] = false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    
    // solution goes here
    cin >> mp;
    

    dfs(0, 0, 0);
    cout << ans << '\n';
}
