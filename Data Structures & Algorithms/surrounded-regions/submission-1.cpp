class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        queue<pair<int, int>> q;

        vector<vector<bool>> vis(n, vector<bool>(m, false));

        for ( int i = 0 ; i < n ; i++ ) {
            for ( int j = 0 ; j < m ; j++ ) {
                if ( i == 0 || j == 0 || i == n-1 || j == m-1 ) {
                    if ( board[i][j] == 'O') {
                        q.push({i,j});
                        vis[i][j] = true;
                    }
                }
            }
        }

        int dx[4] = {1, -1, 0, 0};
        int dy[4] = {0, 0, 1, -1};

        while ( !q.empty() ) {
            int len = q.size();

            while ( len-- ) {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                for ( int i = 0 ; i < 4 ; i++ ) {
                    int nx = x + dx[i];
                    int ny = y + dy[i];

                    if ( nx >= 0 && ny >= 0 && nx < n && ny < m && board[nx][ny] == 'O' && vis[nx][ny] == false ){
                        vis[nx][ny] = true;
                        q.push({nx, ny});
                    }
                }
            }
        }

        for ( int i = 0 ; i < n ; i++ ) {
            for ( int j = 0 ; j < m ; j++ ) {
                if ( vis[i][j] == false ) {
                    if ( board[i][j] == 'O') {
                        board[i][j] = 'X';
                        vis[i][j] = true;
                    }
                }
            }
        }

        return;

    }
};
