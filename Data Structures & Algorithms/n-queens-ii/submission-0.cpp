class Solution {
public:
int res = 0;
vector<bool> cols, posdi, negdi;

    void dfs(int r, int n) {
        if ( r == n ) {
            res++;
            return;
        }

        for ( int c = 0 ; c < n ;c++ ) {
            if ( cols[c] || posdi[r+c] || negdi[r-c+n] ) continue;

            cols[c] = true;
            posdi[r+c] = true;
            negdi[r-c+n] = true;

            dfs(r+1, n);

            cols[c] = false;
            posdi[r+c] = false;
            negdi[r-c+n] = false;
        }

        return;
    }

    int totalNQueens(int n) {
        posdi.resize(2*n, false);
        negdi.resize(2*n, false);
        cols.resize(2*n, false);

        dfs(0, n);
        return res;
    }
};