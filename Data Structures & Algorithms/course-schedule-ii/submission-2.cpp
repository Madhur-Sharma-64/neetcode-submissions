class Solution {
public:

    bool dfs(int src, vector<vector<int>>& pre, vector<bool>& vis, vector<bool>& path ) {
        vis[src] = true;
        path[src] = true;

        for ( int i = 0 ; i < pre.size() ; i++ ) {
            int u = pre[i][1];
            int v = pre[i][0];

            if ( u != src ) continue;

            if ( !vis[v] ) {
                if ( dfs(v, pre, vis, path) ) return true;
            }

            else if ( path[v] ) return true;
        }

        path[src] = false;

        return false;
    }

    bool canFinish(int n, vector<vector<int>>& pre) {
        vector<bool> path(n, false);
        vector<bool> vis(n, false);

        for ( int i = 0 ; i < pre.size() ; i++ ) {

            if ( !vis[pre[i][1]])
            if ( dfs(pre[i][1], pre, vis, path ) ) return false;
        }

        return true;
    }

    void topo ( int x, stack<int>& st, vector<vector<int>>& pre, vector<bool>& vis) {
        vis[x] = true;

        for ( int i = 0 ; i < pre.size() ; i++ ) {
            int u = pre[i][1];
            int v = pre[i][0];

            if ( u != x ) continue;

            else {
                if ( !vis[v] ) topo(v, st, pre, vis);
            }

        }

        st.push(x);

        return;
    }

    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        if ( !canFinish(n, pre) ) return {};

        vector<bool> vis(n, false);
        stack<int> st;

        for ( int i = 0 ; i < n ; i++ ) {

            if ( !vis[i] )
            topo(i, st, pre, vis);
        }

        vector<int> ans;
        while ( st.size() > 0 ) {
            ans.push_back(st.top());

            st.pop();
        }

        return ans;
    }
};
