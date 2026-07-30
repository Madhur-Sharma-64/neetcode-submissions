class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int,int>> q;
        int fresh = 0;
        int time = 0;

        for ( int i = 0 ; i < n ; i++ ) {
            for ( int j = 0 ; j < m ; j++ ) {
                if ( grid[i][j] == 2 ) q.push({i,j});

                else if ( grid[i][j] == 1 ) fresh++;
            }
        }

        int arrx[4] = {1,-1,0,0};
        int arry[4] = {0,0,1,-1};

        if ( fresh == 0 ) return 0;

        while ( !q.empty() ) {
            int len = q.size();

            while ( len > 0 ) {

            
            int it = 4;
            while ( it > 0 ) {
                int next_x = q.front().first + arrx[it-1];
                int next_y = q.front().second + arry[it-1];

                if ( next_x >= 0 && next_y >= 0 && next_x < n && next_y < m && grid[next_x][next_y] == 1) {
                    fresh--;
                    grid[next_x][next_y] = 2;
                    q.push({next_x, next_y});
                }

                it--;

            }
            q.pop();
            len--;
            }
            time++;
        }

        if ( fresh > 0 ) return -1;

        return time - 1 ;

    }
};