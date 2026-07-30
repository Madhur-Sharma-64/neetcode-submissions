class Solution {
public:

    bool solve (int i, int j, vector<vector<char>>& board, string word, int k) {

        if ( k == word.size() ) return true;

        if ( i >= board.size() || j >= board[0].size() || i < 0 || j < 0 ) return false;

        char tmp = board[i][j];
        board[i][j] = '#';
        bool found = false;
        if ( tmp == word[k] ) {
            found = solve(i+1, j, board, word, k+1) ||
            solve(i-1, j, board, word, k+1) ||
            solve(i, j+1, board, word, k+1) ||
            solve(i, j-1, board, word, k+1);
        }
        board[i][j] = tmp;
        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        bool lol = false;

        for ( int i = 0 ; i < n ; i++ ) {
            for ( int j = 0 ; j < m ; j++ ) {
                if ( board[i][j] == word[0] ) {
                    lol = solve(i, j, board, word, 0);
                    if ( lol ) return true;
                }
            }
        }

        return false;
    }
};
