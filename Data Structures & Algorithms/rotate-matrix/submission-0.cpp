class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();

        vector<vector<int>> duplicate;

        for ( int i = 0 ; i < n ; i++ ) {
            vector<int> row;
            for ( int j = 0 ; j < n ; j++ ) {
                row.push_back(matrix[n-1-j][i]);
            }
            duplicate.push_back(row);
        }
        matrix = duplicate;
        return;
    }
};
