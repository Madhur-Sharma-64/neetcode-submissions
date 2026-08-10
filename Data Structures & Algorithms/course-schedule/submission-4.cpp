class Solution {
public:

    bool dfs(int x, vector<bool>& vis, vector<bool>& path,
             vector<vector<int>>& adj) {

        vis[x] = true;
        path[x] = true;

        for (int u : adj[x]) {

            if (!vis[u]) {
                if (dfs(u, vis, path, adj))
                    return true;
            }
            else if (path[u]) {
                return true;
            }
        }

        path[x] = false;
        return false;
    }

    bool canFinish(int n, vector<vector<int>>& pre) {

        vector<bool> vis(n, false);
        vector<bool> path(n, false);

        vector<vector<int>> adj(n);

        for (auto& p : pre) {
            int course = p[0];
            int prerequisite = p[1];

            adj[prerequisite].push_back(course);
        }

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                if (dfs(i, vis, path, adj))
                    return false;
            }
        }

        return true;
    }
};