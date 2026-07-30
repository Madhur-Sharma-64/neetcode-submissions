class Solution {
public:  

    void dfs (int i , int j , int n , int m , vector<vector<bool>> &visited , vector<vector<char>>& grid) {
        if ( i < 0 || j < 0 || i >= n || j >= m || visited[i][j] == true || grid[i][j] != '1' )
        return;

        visited[i][j] = true;

        dfs( i-1, j, n, m, visited, grid);
        dfs( i+1, j, n, m, visited, grid);
        dfs( i, j-1, n, m, visited, grid);
        dfs( i, j+1, n, m, visited, grid);

        return;
    }


    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bool>> visited(n, vector<bool>(m, false));
        int ans = 0;

        for ( int i = 0 ; i < n ; i++ ) {
            for ( int j = 0 ; j < m ; j++ ) {
                if ( grid[i][j] == '1' && visited[i][j] == false) {
                    dfs(i, j, n , m, visited, grid);
                    ans++;
                }
            }
        }
        return ans;
    }
};
