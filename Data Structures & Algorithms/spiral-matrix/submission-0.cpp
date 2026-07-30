class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> ans;

        for (int i = 0; i < (min(n, m) + 1) / 2; i++) {

            // Top row
            for (int j = i; j < m - i; j++) {
                ans.push_back(matrix[i][j]);
            }

            // Right column
            for (int j = i + 1; j < n - i; j++) {
                ans.push_back(matrix[j][m - 1 - i]);
            }

            // Bottom row (only if different from top row)
            if (n - 1 - i > i) {
                for (int j = i + 1; j < m - i; j++) {
                    ans.push_back(matrix[n - 1 - i][m - 1 - j]);
                }
            }

            // Left column (only if different from right column)
            if (m - 1 - i > i) {
                for (int j = i + 1; j < n - 1 - i; j++) {
                    ans.push_back(matrix[n - 1 - j][i]);
                }
            }
        }

        return ans;
    }
};