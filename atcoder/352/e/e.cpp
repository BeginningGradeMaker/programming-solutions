#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int INF = 0x3f3f3f3f;
int mod = 1e9 + 7;
int N = 200005;

class DisjointSet {
public:
    vector<int> parent;
    vector<int> size;

    DisjointSet(int n) {
        parent.resize(n);
        size.resize(n);

        for (int i = 0; i < n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int find(int x) {
        if (x == parent[x]) {
            return x;
        }

        return parent[x] = find(parent[x]);
    }

    bool same(int a, int b) { return find(a) == find(b); }

    void union_sets(int a, int b) {
        a = find(a);
        b = find(b);
        if (a != b) {
            if (size[a] < size[b]) swap(a, b);
            size[a] += size[b];
            parent[b] = a;
        }
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // Input handling goes here
    int N, M; cin >> N >> M;
    vector<vector<int>> A(M);
    vector<int> C(M);
    DisjointSet s(N);

    for (int i = 0; i < M; i++) {
        int K; cin >> K >> C[i];
        A[i].resize(K);
        for (int j = 0; j < K; j++) {
            int x; cin >> x;
            x--;
            A[i][j] = x;
        }
    }

    vector<int> idx(M);
    iota(idx.begin(), idx.end(), 0);
    sort(idx.begin(), idx.end(), [&] (int i, int j) {
        return C[i] < C[j];
    });

    ll ans = 0;
    int comp = N;
    for (int i : idx) {
        for (int j = 1; j < (int)A[i].size(); j++) {
            if (s.find(A[i][j]) != s.find(A[i][j-1])) {
                s.union_sets(A[i][j], A[i][j-1]);
                ans += C[i];
                comp--;
            }
        }
    }

    if (comp > 1) {
        ans = -1;
    }

    cout << ans << endl;
}
