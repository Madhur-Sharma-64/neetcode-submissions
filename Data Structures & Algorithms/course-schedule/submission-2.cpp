class Solution {
public:

    bool dfs(int x, vector<vector<int>>& pre, vector<bool>& vis, vector<bool>& path) {
        vis[x] = true;
        path[x] = true;

        for ( int i = 0 ; i < pre.size() ; i++ ) {
            int u = pre[i][0];
            int v = pre[i][1];

            if ( v != x ) continue;

            if ( !vis[u] ) {
                if ( dfs(u, pre, vis, path ) ) return true;
            } else if ( path[u] == true ) return true;
        }

        path[x] = false;

        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& pre) {
        vector<bool> vis(numCourses, false);
        vector<bool> path(numCourses, false);

        for ( auto lol : pre ) {
            int y = lol[1];
            int x = lol[0];

            if ( !vis[x] ) {
                if ( dfs(x, pre, vis, path) ) return false;
            }
        }

        return true;
    }
};
