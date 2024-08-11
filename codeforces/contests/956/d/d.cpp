#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int INF = 0x3f3f3f3f;
int mod = 1e9 + 7;
int N = 200005;

int inversions(vector<int> &v, int l, int r) {
    if (l == r) return 0;
    int n = r - l + 1;
    // Divide and conquer
    int mid = (l + r) / 2;
    int left_cnt = inversions(v, l, mid);
    int right_cnt = inversions(v, mid + 1, r);

    int ans = 0;
    vector<int> sorted(n);
    int i = l, j = mid + 1;
    for (int k = 0; k < n; k++) {
        if (i > mid) {
            sorted[k] = v[j++];
        } else if (j > r) {
            sorted[k] = v[i++];
            ans += n / 2;
            /*cout << "(" << i << ", " << j << "): " << ans << endl;*/
        } else if (v[i] < v[j]) {
            sorted[k] = v[i++];
            ans += (j - mid - 1);
            /*cout << "(" << i << ", " << j << "): " << ans << endl;*/
        } else {
            sorted[k] = v[j++];
            /*cout << "(" << i << ", " << j << "): " << ans << endl;*/
        }
    }

    for (int k = 0; k < n; k++) {
        v[l + k] = sorted[k];
    }

    return left_cnt + right_cnt + ans;
}


void solve() {
    // Solution goes here
    int n; cin >> n;
    vector<int> a(n);
    vector<int> b(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    // First, if two arrays don't have same multiset
    // of elements, they can't be equal with any number
    // of operations.
    // Note that for any swap opreation (l, r), it
    // is equilvalent to multiple consecutive swaps.
    // For example: (1, 2, 3) -> (3, 2 ,1) can be
    // converted to
    //  (1, 2, 3) -> (2, 1, 3) -> (2, 3, 1) -> (3, 2, 1)
    // The detailed proof is omitted.
    // Now, note that every consecutive swap change the
    // number of inversions in the array by exactly 1, which
    // means its parity will change at every swap. Therefore,
    // if a and b have different parity, it will never be the
    // same.
    // Otherwise, if a and b have same parity (with same 
    // multiset), then one can show that we can always
    // make swaps to make them equal. The idea is to
    // keep swapping (1, 2) in a and swap b such that
    // b[i] == a[i] for all i = 3,...,n. At this point we
    // must have a[1] == b[1] and a[2] == b[2] otherwise
    // the parity of a and b will be different. This proves
    // our claim.
    set<int> s1, s2;
    for (int i = 0; i < n; i++) {
        s1.insert(a[i]);
        s2.insert(b[i]);
    }
    if (s1 != s2) {
        cout << "NO" << endl;
        return;
    }

    /*cout << "inversions of a: " << inversions(a, 0, n-1) << endl;*/
    /*cout << "inversions of b: " << inversions(b, 0, n-1) << endl;*/
    if ((inversions(a, 0, n-1) & 1) != (inversions(b, 0, n-1) & 1)) {
        cout << "NO" << endl;
        return;
    }

    cout << "YES" << endl;
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
