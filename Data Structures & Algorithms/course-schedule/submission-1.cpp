class Solution {
public:

    bool dfs ( int x, vector<vector<int>>& pre, vector<bool>& vis, vector<bool>& path ) {
        vis[x] = true;
        
        path[x] = true;

        for ( int i = 0 ; i < pre.size() ; i++ ) {
            int u = pre[i][0];
            int v = pre[i][1];

            if ( v != x ) continue;

            if ( vis[u] == false ) {
                if ( dfs(u, pre, vis, path) == true ) return true;
            }
            else if ( path[u] == true ) return true;
        }

        path[x] = false;

        return false;
    }

    bool canFinish(int n, vector<vector<int>>& pre) {
        vector<bool> vis(n, false);
        vector<bool> path(n, false);

        for (auto p : pre ) {
            int y = p[1];
            int x = p[0];

            if ( vis[x] == false ) {
                if ( dfs(x, pre, vis, path) == true ) return false;
            }
        }

        return true;
    }
};
