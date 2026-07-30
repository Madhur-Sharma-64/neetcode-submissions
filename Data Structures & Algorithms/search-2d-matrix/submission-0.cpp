class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int left = 0;
        int right = matrix.size() - 1;
        
        while ( left <= right ) {
            int idx = (left + right) / 2;

            if ( matrix[idx][0] == target )
            return true;

            if ( matrix[idx][0] > target )
            right = idx - 1;

            if ( matrix[idx][0] < target ) {
                int first = 0;
                int last = matrix[idx].size() - 1;

                while ( first <= last ) {
                    int mid = (first+last) / 2;
                    if ( matrix[idx][mid] == target )
                    return true;

                    if ( matrix[idx][mid] > target )
                    last = mid - 1;

                    if ( matrix[idx][mid] < target )
                    first = first + 1;
                }

                left = idx + 1 ;
            }
        }

        return false;
    }
};
