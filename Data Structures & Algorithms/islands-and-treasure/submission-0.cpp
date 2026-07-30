class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {

        int inf = INT_MAX;


        int arrx[4] = {1,-1,0,0};
        int arry[4] = {0,0,1,-1};

        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int, int>> q;
        //vector<vector<bool>> visited(n, vector<bool>(m, false));

        for ( int i = 0 ; i < n ; i++ ){
            for ( int j = 0 ; j < m ; j++ ) {
                if ( grid[i][j] == 0 ) {
                    q.push({i,j});
                   // visited[i][j] = true;
                }
            }
        }

        int ans = 1;

        while ( !q.empty() ) {
            int len = q.size() ; 
            //q.pop();
            while ( len-- ) {
                int it = 0;
                int x = q.front().first;
                int y = q.front().second;
                q.pop();

                for ( int it = 0 ; it < 4 ; it++ ) {
                    int nx = x + arrx[it];
                    int ny = y + arry[it];

                    if ( nx >= 0 && ny >= 0 && nx < n && ny < m && grid[nx][ny] == inf ) {
                        grid[nx][ny] = ans;
                        q.push({nx,ny});
                    }
                }
            }

            ans++;
           // q.pop();
        }

        return;


    }
};
