class Solution {
public:

    int helper (int i, vector<int>& nums, int target ) {

        if ( i == nums.size() )  {
            if ( target == 0 ) return 1;

            else return 0;
        }
        

        int add = 0;
        add += helper(i+1, nums, target-nums[i]);

        int sub = 0;
        sub += helper(i+1, nums, target+nums[i]);

        

        return add+sub;
    }


    int findTargetSumWays(vector<int>& nums, int target) {
        return helper(0, nums, target);
    }
};
