#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int INF = 0x3f3f3f3f;
int mod = 1e9 + 7;
int N = 200005;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // Input handling goes here
    int N, K; cin >> N >> K;
    vector<int> A(N);

    for (int &x : A) cin >> x;

    int cur = K;
    int ans = 0;
    int i = 0;
    while (i < N) {
        if (cur >= A[i]) {
            cur -= A[i];
            i++;
            continue;
        }

        cur = K;
        ans++;
    }

    cout << ans + 1 << endl;

}
