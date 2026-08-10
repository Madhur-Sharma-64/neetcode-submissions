class Solution {
public:

    int find ( vector<int>& par, int n) {
        if ( n == par[n] ) return n;

        return par[n] = find(par, par[n]);
    }

    bool unin( vector<int>& par, vector<int>& rank, int x, int y) {
        int p1 = find(par, x);
        int p2 = find(par, y);

        if ( p1 == p2 ) return false;

        else if ( rank[p1] > rank[p2] ) {
            par[p2] = p1;
            rank[p1] += rank[p2];
        }
        else {
            par[p1] = p2;
            rank[p2] += rank[p1];
        }

        return true;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> par(n+1);
        vector<int> rank(n+1, 1);

        for ( int i = 1 ; i <= n ; i++ ) par[i] = i;

        for ( auto& e : edges ) {
            int x = e[0];
            int y = e[1];

            if ( !unin(par, rank, x, y) ) return e;
        }

        return {};
    }
};
