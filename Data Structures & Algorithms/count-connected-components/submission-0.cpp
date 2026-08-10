class Solution {
public:

    void isc ( int x, vector<vector<int>>& adj, vector<bool>& vis) {
        vis[x] = true;

        for ( auto u : adj[x] ) {
            if ( !vis[u] ) {
                isc(u, adj, vis);
            } 
        }

        return ;
    }

    int countComponents(int n, vector<vector<int>>& edges) {
        int len = edges.size();
        vector<vector<int>> adj(n);

        for ( auto& e : edges ) {
            int a = e[0];
            int b = e[1];

            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        vector<bool> vis(len, false);
        int count = 0;

        for ( int x = 0 ; x < n ; x++ ) {
            if ( !vis[x] ) {
                isc(x, adj, vis);
                count++;
            }
        }

        return count;
    }
};
