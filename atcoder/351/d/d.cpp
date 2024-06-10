#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int INF = 0x3f3f3f3f;
int mod = 1e9 + 7;
int N = 1000005;

vector<int> dx = {1, -1, 0, 0};
vector<int> dy = {0, 0, 1, -1};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // Input handling goes here
    int H, W;
    cin >> H >> W;

    vector<string> grid(H);
    for (auto &s : grid) cin >> s;

    auto valid = [&] (int i, int j) {
        return i >= 0 && i < H && j >= 0 && j < W;
    };

    vector<vector<int>> parent(H, vector<int>(W, -1));
    vector<vector<bool>> magnet(H, vector<bool>(W, false));

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (grid[i][j] == '#') {
                for (int k = 0; k < 4; k++) {
                    int x = i + dx[k];
                    int y = j + dy[k];

                    if (valid(x, y)) {
                        magnet[x][y] = true;
                    }
                }
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (parent[i][j] == -1 && grid[i][j] == '.') {
                parent[i][j] = i * H + j;
                queue<pair<int, int>> Q;
                Q.emplace(i, j);
                int cnt = 0;

                while (!Q.empty()) {
                    int x = Q.front().first;
                    int y = Q.front().second;
                    Q.pop();

                    cnt++;
                    
                    // unmovable
                    if (magnet[x][y]) continue;

                    for (int k = 0; k < 4; k++) {
                        int nx = x + dx[k];
                        int ny = y + dy[k];

                        if (valid(nx, ny) && parent[nx][ny] != i * H + j) {
                            Q.emplace(nx, ny);
                            parent[nx][ny] = i * H + j;
                        }
                    }
                }

                ans = max(ans, cnt);
            }
        }
    }

    cout << ans << endl;
}
