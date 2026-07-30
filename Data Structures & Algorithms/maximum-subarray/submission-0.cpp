class Solution {
public:

    int solve ( int i, vector<int>& nums, vector<int>& dp) {
        if ( i >= nums.size() ) return 0;

        if ( i == nums.size() - 1 ) return nums[i];

        if ( dp[i] != INT_MIN ) return dp[i];

        int sum = 0;
        sum = nums[i] + max(0, solve(i+1, nums, dp));

        return dp[i] = sum;
    }

    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, INT_MIN);

        int ans = INT_MIN;

        for ( int i = 0 ; i < n ; i++ ) 
            ans = max(ans, solve(i, nums, dp));

        return ans;
        
    }
};
