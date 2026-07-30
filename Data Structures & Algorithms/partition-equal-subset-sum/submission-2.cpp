class Solution {
public:

    int solve ( int i , int n, vector<int>& nums, vector<vector<int>>& dp,int target) {
        if ( target == 0 ) return 1;

        if ( i >= n || target < 0 ) return 0;

        if ( dp[i][target] != -1 ) return dp[i][target];

        int take = 0;
        take += solve ( i+1, n, nums, dp, target-nums[i]);

        int no = 0;
        no += solve(i+1, n, nums, dp, target);

        return dp[i][target] = max(take, no);
    }


    bool canPartition(vector<int>& nums) {

        int n = nums.size();

        int sum = 0;
        for ( int i = 0 ; i < n ; i++) sum+=nums[i];

        if ( sum%2 == 1 ) return false;

        sum = sum/2;

        vector<vector<int>> dp(n, vector<int>(sum+1, -1));

        if ( solve(0, n, nums, dp, sum) == 1 ) return true;

        return false;
        
    }
};
