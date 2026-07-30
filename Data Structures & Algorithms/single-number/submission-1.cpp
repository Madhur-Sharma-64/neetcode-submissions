class Solution {
public:
    int singleNumber(vector<int>& nums) {
        if ( nums.size() % 2 == 0 ) return -1;
        if ( nums.size() == 1 ) return nums[0];

        int slow = 0;
        int fast = 1;

        while ( slow < nums.size() - 1 ) {
            if ( nums[slow] != nums[fast] ) {
                if ( fast == nums.size() - 1 ) {
                    slow++;
                    fast = slow + 1;
                }
                
                else 
                fast++;
            }
            else {
                nums[slow] = -1;
                nums[fast] = -1;
                slow++;
                fast = slow + 1;
            }
        }
        for ( int i = 0 ; i < nums.size() ; i++ ){
            if ( nums[i] != -1 )
            return nums[i];
        }
        return -1;
    }
};
