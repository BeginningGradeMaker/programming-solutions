class Solution {
    int ans = 0;
    int dfs(vector<vector<int>> &adj, int u, int p) {
        vector<int> cnt;
        for (int v : adj[u]) {
            if (v != p) {
                cnt.push_back(dfs(adj, v, u));
            }
        }

        int ok = true;
        for (int i = 0; i < cnt.size() - 1; i++) {
            if (cnt[i] != cnt[i+1]) {
                ok = false;
                break;
            }
        }

        if (ok) {
            ans++;
        }

        return cnt.empty() ? 1 : accumulate(cnt.begin(), cnt.end(), 0) + 1;
    }
public:
    int countGoodNodes(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        vector<vector<int>> adj(n);
        for (auto edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        dfs(adj, 0, -1);
        
        return ans;
    }
};
