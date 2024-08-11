class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        int q = queries.size();
        set<int> nums;
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            nums.insert(i);
        }
        
        for (int i = 0; i < q; i++) {
            if (nums.size() <= 2) {
                ans.push_back(1);
                continue;
            }
            int l = queries[i][0], r = queries[i][1];
            auto it_l = nums.upper_bound(l);
            auto it_r = nums.lower_bound(r);
            nums.erase(it_l, it_r);
            ans.push_back(nums.size()-1);
        }

        return ans;
    }
};
