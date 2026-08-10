class Solution {
public:

    bool dfs ( int x, vector<vector<int>>& pre, vector<bool>& vis, vector<bool>& path, vector<vector<int>>& adj ) {
        vis[x] = true;
        
        path[x] = true;

        for ( int u : adj[x]) {

            if ( vis[u] == false ) {
                if ( dfs(u, pre, vis, path, adj) == true ) return true;
            }
            else if ( path[u] == true ) return true;
        }

        path[x] = false;

        return false;
    }

    bool canFinish(int n, vector<vector<int>>& pre) {
        vector<bool> vis(n, false);
        vector<bool> path(n, false);

        vector<vector<int>> adj(n);
        for ( auto& p : pre ) {
            int b = p[1];
            int a = p[0];

            adj[b].push_back(a);
        }
        for (auto p : pre ) {
            int y = p[1];
            int x = p[0];

            if ( vis[x] == false ) {
                if ( dfs(x, pre, vis, path, adj) == true ) return false;
            }
        }

        return true;
    }
};
