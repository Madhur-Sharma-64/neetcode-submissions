class Solution {
public:
    int findMin(vector<int> &nums) {

        int left = 0 ; 
        int right = nums.size() - 1;
        int mid;
        while ( left <= right ) {
            mid = (left + right) / 2;

            if ( nums[left] <= nums[right] )
            return nums[left];

            if ( mid != 0 && nums[mid] < nums[mid-1] ) {
                return nums[mid];
            }

            if ( nums[mid] > nums[right] ){
                left = mid + 1;
            }

            if ( nums[mid] < nums[right] ) {
                right = mid - 1;
            }

            if ( left == right )
            return nums[left];
        }

        return nums[mid];
    }
};
