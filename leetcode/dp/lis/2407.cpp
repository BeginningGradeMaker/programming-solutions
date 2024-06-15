class Solution {

struct SegmentTree {
    int n;
    vector<int> val;
    SegmentTree(int n): n(n), val(4 * n, 1) {}

    void build(vector<int> &a, int v, int tl, int tr) {
        if (tl == tr) {
            val[v] = a[tl];
        } else {
            int tm = (tl + tr) / 2;
            build(a, v * 2, tl, tm);
            build(a, v * 2 + 1, tm + 1, tr);
            val[v] = max(val[v*2], val[v*2+1]);
        }
    }

    void build(vector<int> &a) {
        build(a, 1, 0, n-1);
    }

    int sum(int v, int tl, int tr, int l, int r) {
        // cout << l << ' ' << r << endl;
        if (l > r) {
            return 0;
        }
        if (tl == l && tr == r) {
            return val[v];
        }
        int tm = (tl + tr) / 2;
        return max(sum(v*2, tl, tm, l, min(r, tm)), sum(v*2+1, tm+1, tr, max(l, tm+1), r));
    }

    int sum(int l, int r) {
        return sum(1, 0, n-1, l, r);
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
            val[v] = max(val[2*v], val[2*v+1]);
        }
    }

    void update(int pos, int new_val) {
        update(1, 0, n-1, pos, new_val);
    }
};

public:
    int lengthOfLIS(vector<int>& nums, int k) {
        int n = nums.size();
        int mx = *max_element(nums.begin(), nums.end());
        SegmentTree T(4 * mx + 1);
        // T.build(nums);

        for (int i = 0; i < n; i++) {
            T.update(nums[i], max(T.sum(nums[i], nums[i]), T.sum(max(0, nums[i]-k), nums[i]-1) + 1));
        }

        // for (int i = 0; i < 4 * mx; i++) {
        //     cout << T.val[i] << ' ';
        // }
        // cout << endl;

        return max(1, T.sum(0, 4 * mx) - 1);
    }
};
