class Solution {
public:
vector<vector<string>> res;

vector<bool> posdi;
vector<bool> cols;
vector<bool> negdi;

    void dfs(int r, int n, vector<string>& board) {
        if ( r == n ) {
            res.push_back(board);
            return;
        }

        for ( int c = 0 ; c < n ; c++ ) {
            if ( cols[c] || posdi[r+c] || negdi[r-c+n] ) continue;

            cols[c] = true;
            posdi[r+c] = true;
            negdi[r-c+n] = true;

            board[r][c] = 'Q';
            dfs(r+1, n, board);

            cols[c] = false;
            posdi[r+c] = false;
            negdi[r-c+n] = false;

            board[r][c] = '.';
        }

        return;

    }

    vector<vector<string>> solveNQueens(int n) {
        if ( n == 1 ) return {{"Q"}};

        posdi.resize(2*n, false);
        cols.resize(2*n, false);
        negdi.resize(2*n, false);

        vector<string> board(n, string(n, '.'));
        dfs(0, n, board);
        return res;

    }
};
