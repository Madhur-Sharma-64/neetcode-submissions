class Solution {
public:
    void dfs(vector<vector<int>>& heights,
             vector<vector<bool>>& visited,
             int i, int j, int prevHeight) {

        int n = heights.size();
        int m = heights[0].size();

        if (i < 0 || i >= n || j < 0 || j >= m)
            return;

        if (visited[i][j])
            return;

        if (heights[i][j] < prevHeight)
            return;

        visited[i][j] = true;

        dfs(heights, visited, i + 1, j, heights[i][j]);
        dfs(heights, visited, i - 1, j, heights[i][j]);
        dfs(heights, visited, i, j + 1, heights[i][j]);
        dfs(heights, visited, i, j - 1, heights[i][j]);
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {

        int n = heights.size();
        int m = heights[0].size();

        vector<vector<bool>> pac(n, vector<bool>(m, false));
        vector<vector<bool>> atl(n, vector<bool>(m, false));

        // Pacific (top row)
        for (int j = 0; j < m; j++)
            dfs(heights, pac, 0, j, heights[0][j]);

        // Pacific (left column)
        for (int i = 0; i < n; i++)
            dfs(heights, pac, i, 0, heights[i][0]);

        // Atlantic (bottom row)
        for (int j = 0; j < m; j++)
            dfs(heights, atl, n - 1, j, heights[n - 1][j]);

        // Atlantic (right column)
        for (int i = 0; i < n; i++)
            dfs(heights, atl, i, m - 1, heights[i][m - 1]);

        vector<vector<int>> ans;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (pac[i][j] && atl[i][j]) {
                    ans.push_back({i, j});
                }
            }
        }

        return ans;
    }
};