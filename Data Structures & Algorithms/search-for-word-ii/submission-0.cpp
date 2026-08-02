class Solution {
public:
int n, m;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
unordered_set<string> found;

    void dfs ( int i, int j, int curr, vector<vector<char>>& board, string& word, vector<string>& res ) {
        if ( board[i][j] != word[curr] ) return;

        if ( found.count(word) ) return;

        if ( curr == word.size() - 1 ) {
            res.push_back(word);
            found.insert(word);
            return;
        }
        
        if (i >= n || j >= m || i < 0 || j < 0 ) return;
        
        char tmp = board[i][j];

        board[i][j] = '*';

        for ( int idx = 0 ; idx < 4 ; idx++ ) {
            int nx = i + dx[idx];
            int ny = j + dy[idx];

            if ( nx >= 0 && ny >= 0 && nx < n && ny < m && board[nx][ny] != '*') {
                dfs(nx, ny, curr+1, board, word, res);
            }

        }
        board[i][j] = tmp;

        return;

    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> res;
        n = board.size();
        m = board[0].size();

        for ( int i = 0 ; i < n ; i++ ) {
            for ( int j = 0 ; j < m ; j++ ) {
                for ( string word : words ) {
                    //vector<vector<bool>> vis(n, vector<bool>(m, false));
                    if ( board[i][j] == word[0] ) dfs(i, j, 0, board, word, res);
                }
            }
        }

        return res;

    }
};
