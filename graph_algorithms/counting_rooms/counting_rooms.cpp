#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int mod = 1000000007;
vector<int> nbr = {1, 0, -1, 0, 1};

int main() {
    // solution goes here
    int n, m;
    cin >> n >> m;
    vector<vector<bool>> map(n, vector<bool>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char c; cin >> c;
            map[i][j] = c == '.';
        }
    }

    queue<pair<int, int>> Q;
    auto bfs = [&] (int i, int j) {
        Q.push({i, j});
        map[i][j] = false;

        while (!Q.empty()) {
            auto pair = Q.front();
            int r = pair.first, c = pair.second;
            Q.pop();

            for (int k = 0; k < 4; k++) {
                int r1 = r + nbr[k], c1 = c + nbr[k+1];
                if (r1 >= 0 && r1 < n &&
                    c1 >= 0 && c1 < m &&
                    map[r1][c1]) {
                    Q.push({r1, c1});
                    map[r1][c1] = false;
                }
            }
        }
    };

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (map[i][j]) {
                bfs(i, j);
                cnt++;
            }
        }
    }
    
    cout << cnt;
}
