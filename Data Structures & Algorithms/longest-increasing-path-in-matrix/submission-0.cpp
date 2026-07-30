class Solution {
public:

    int dfs( int i, int j, int n, int m, vector<int>& path, vector<vector<int>>& matrix, vector<vector<int>>& dp) {
        if ( i >= n || j >= m || i < 0 || j < 0 ) return 0;

        if ( dp[i][j] != -1 ) return dp[i][j];

        int len = 1;

        int dx[4] = {1, -1, 0, 0};
        int dy[4] = {0, 0, 1, -1};

        for ( int l = 0 ; l < 4 ; l++ ) {
            int nx = i + dx[l];
            int ny = j + dy[l];

            if ( nx < n && ny < m && nx >= 0 && ny >= 0 && matrix[nx][ny] > matrix[i][j] ) {
                len = max(len, 1 + dfs(nx, ny, n, m, path, matrix, dp));
            }
        }

        
        return dp[i][j] = len;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<int>> dp(n, vector<int>(m, -1));
        vector<int> path;

        int ans = 0;

        for ( int i = 0 ; i < n ; i++ ) {
            for ( int j = 0 ; j < m ;j++ ) {
                ans = max( ans, dfs(i, j, n, m, path, matrix, dp));
            }
        }

        return ans;
    }
};
