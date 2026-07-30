class Solution {
public:

    int dfs (int i , int j , int n, int m, vector<vector<bool>>& visited, vector<vector<int>>& grid) {
        if ( i < 0 || j < 0 || i >=n || j >= m || visited[i][j] == true || grid[i][j] != 1 ) {
            return 0;
        }

        visited[i][j] = true;

        
        return 1 + dfs(i+1, j, n, m , visited, grid)+
        dfs(i-1, j, n, m, visited, grid)+
        dfs(i, j-1, n, m, visited, grid)+
        dfs(i, j+1, n, m, visited, grid);

    }


    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int sum = 0;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));

        for ( int i = 0 ; i < n ; i++ ) {
            for ( int j = 0 ; j < m ; j++ ) {
                if ( grid[i][j] == 1 && visited[i][j] == false ) {
                    
                    sum = max(sum, dfs(i,j,n,m,visited, grid));
                }
            }
        }

        return sum;


    }
};
