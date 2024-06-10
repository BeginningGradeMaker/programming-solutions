#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int INF = 0x3f3f3f3f;
int mod = 1e9 + 7;
int N = 200005;

void solve() {
    // Solution goes here
    int n, q; cin >> n >> q;

    vector<int> arr1;
    vector<int> arr2;

    for (int i = 3; i <= n; i++) {
        arr1.emplace_back(i);
    }

    for (int i = 1; i < n; i++) {
        cout << i << ' ' << i + 1 << endl;
    }

    for (int i = 0; i < q; i++) {
        int d; cin >> d; d--;
        /*cout << d << endl;*/
        int x = arr1.size();
        if (x == d) {
            cout << -1 << ' ' << -1 << ' ' << -1 << endl;
        } else if (x < d) {
            int t = d - x;
            stack<int> stk;
            while (t--) {
                stk.push(arr2.back());
                arr2.pop_back();
            }
            cout << stk.top() << ' ' << (arr2.empty() ? 2 : arr2.back()) << ' ' << (arr1.empty() ? 2 : arr1.back()) << endl;
            while (!stk.empty()) {
                arr1.push_back(stk.top());
                stk.pop();
            }
        } else {
            int t = x - d;
            stack<int> stk;
            while (t--) {
                stk.push(arr1.back());
                arr1.pop_back();
            }
            cout << stk.top() << ' ' << (arr1.empty() ? 2 : arr1.back()) << ' ' << (arr2.empty() ? 2 : arr2.back()) << endl;
            while (!stk.empty()) {
                arr2.push_back(stk.top());
                stk.pop();
            }
        }
    }
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
