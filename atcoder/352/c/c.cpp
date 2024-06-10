#include <algorithm>
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
    int N; cin >> N;
    vector<ll> A(N), B(N);

    for (int i = 0; i < N; i++) {
        cin >> A[i] >> B[i];
        B[i] -= A[i];
    }

    cout << accumulate(A.begin(), A.end(), 0ll) + *max_element(B.begin(), B.end()) << endl;
}
