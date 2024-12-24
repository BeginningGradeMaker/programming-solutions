#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Range queries are a sequence of ranges [a_i, b_i], i = 1, ..., n.
// The problem could be asking to retrive information such as the sum
// of the elements in the range, the max/min element in the range, or 
// any other information that could be obtained from the given range.
//
// Segment Tree is a data structure that can be used for range query.
// It can answer dynamic query in O(log n) by maintaining range update
// with O(log n) time.
// 

// Info usually represents a node in the segment tree that stores informaiton
// about 
template<class Info>
class SegmentTree {
    int n;
    std;:vector<Info> info;

    // Constructors
    SegmentTree(int n, Info v) {
        init(vector<);
    }
    // Left child
    inline int l(int u) {
        return (u + 1) << 1;
    }
    // Right child
    inline int r(int u) {
        return (u + 1) << 1 - 1;
    }
    // Right child
    void init(vector<Info> init_info) {
        int n = init_info.size();
        info.resize(n);

    }
};
