#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int INF = 0x3f3f3f3f;
int mod = 1e9 + 7;
int N = 200005;

struct Edge {
    int u, v, w;
};

vector<vector<int>> floyd_warshall(vector<Edge> edges, int n, int s) {
    // D[u, v, k] = min weight of walk from u to v which only
    // passes through {v1, v2, ... , vk}
    // 
    // Base: D[u, v, 0] =
    //  1. 0 if u = v
    //  2. w_uv if (u, v) \in E
    //  3. inf if (u, v) \notin E, u != v
    // 
    // Inductive: D[u, v, k] = min of
    //  1. D[u, v, k-1]
    //  2. D[u, vk, k-1] + D[vk, v, k-1]
    vector<vector<vector<int>>> D(n, vector<vector<int>>(n, vector<int>(n+1, INF)));
    for (int i = 0; i < n; i++) {
        D[i][i][0] = 0;
    }
    for (auto edge : edges) {
        D[edge.u][edge.v][0] = edge.w;
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                D[i][j][k] = min(D[i][j][k-1], D[i][k][k-1] + D[k][j][k-1]);
            }
        }
    }

    vector<vector<int>> ans(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            ans[i][j] = D[i][j][n];
        }
    }
    return ans;
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
