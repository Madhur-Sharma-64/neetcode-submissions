class Solution {
public:

    int pivot(vector<int>& nums) {
        int left = 0 ;
        int right = nums.size() - 1;

         if ( nums[left] <= nums[right] ) return 0;

        while ( left < right ) {
            int mid = ( left + right ) / 2;

            if ( nums[mid] > nums[right] ){
                left = mid + 1;
            }
            else {
                right = mid;
            }
        }
        return left;
    }


    int search(vector<int>& nums, int target) {
        int rot = pivot(nums);

        int first, last, mid;

        if ( rot != 0 ) {
            if ( target >= nums[0] ) {
                first = 0;
                last = rot - 1;
            }
            else {
                first = rot;
                last = nums.size() - 1;
            }
        }
        else {
            first = 0;
            last = nums.size() - 1;
        }

        
        while ( first <= last ) {

            mid = ( first + last ) / 2;

            if ( nums[mid] == target ) return mid;

            if ( nums[mid] < target ) first = mid + 1;

            else last = mid - 1;
                    
        }

        return -1;
    }
};
