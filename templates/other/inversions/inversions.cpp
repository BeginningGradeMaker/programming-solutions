#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

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
