#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct SegmentTree {
    int n;
    vector<int> val;
    SegmentTree(int n): n(n), val(4 * n) {}

    void build(vector<int> &a, int v, int tl, int tr) {
        if (tl == tr) {
            val[v] = a[tl];
        } else {
            int tm = (tl + tr) / 2;
            build(a, v * 2, tl, tm);
            build(a, v * 2, tm + 1, tr);
            val[v] = val[v*2] + val[v*2+1];
        }
    }

    void build(vector<int> &a) {
        build(a, 0, 0, n-1);
    }

    int sum(int v, int tl, int tr, int l, int r) {
        if (tl > l || tr < r) {
            return 0;
        }
        if (tl == l && tr == r) {
            return val[v];
        }
        int tm = (tl + tr) / 2;
        return sum(v*2, tl, tm, l, min(r, tm)) + sum(v*2+1, tl+1, tr, max(l, tm+1), r);
    }

    int sum(int l, int r) {
        return sum(0, 0, n-1, l, r);
    }

    void update(int v, int tl, int tr, int pos, int new_val) {
        if (tl == tr) {
            val[v] = new_val;
        } else {
            int tm = (tl + tr) / 2;
            if (pos <= tm) {
                update(2*v, tl, tm, pos, new_val);
            } else {
                update(2*v+1, tm+1, tr, pos, new_val);
            }
            val[v] = val[2*v] + val[2*v+1];
        }
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // Input handling goes here
    int t; cin >> t;
}
