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
    int N, M; cin >> N >> M;
    vector<pair<int, int>> arr;

    for (int i = 0; i < N; i++) {
        int x; cin >> x;
        arr.emplace_back(x, 0);
    }
    for (int i = 0; i < M; i++) {
        int x; cin >> x;
        arr.emplace_back(x, 1);
    }

    sort(arr.begin(), arr.end());
    for (int i = 0; i < N + M - 1; i++) {
        if (arr[i].second == 0 && arr[i+1].second == 0) {
            cout << "Yes" << endl;
            return 0;
        }
    }

    cout << "No" << endl;
}
