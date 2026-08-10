class Solution {
public:

    bool isc ( int x, int parent, vector<vector<int>>& adj, vector<bool>& vis) {
        vis[x] = true;
        
        for ( auto u : adj[x] ) {
            if ( u == parent ) continue;

            else if ( !vis[u] ) {
                if ( isc(u, x, adj, vis) ) return true;
            } else return true;
        }


        return false;
    }

    bool validTree(int n, vector<vector<int>>& edges) {

        if ( n != edges.size() + 1 ) return false;

        vector<bool> vis(n, false);
        vector<vector<int>> adj(n);

        for ( auto& e : edges ) {
            int u = e[0];
            int v = e[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        if ( isc(0, -1, adj, vis) ) return false;

        for ( int i = 0 ; i < n ; i++ ) {
            if ( !vis[i] ) return false;
        }

        return true;
    }
};
