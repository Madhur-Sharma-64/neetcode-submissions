class Solution {
public:

    int solve ( int i, int prev, int n, vector<int>& nums, vector<vector<int>>& dp) {
        if ( i >= n ) return 0;

        if ( dp[i][prev+1] != -1 ) return dp[i][prev+1];

        int not_include = solve(i+1, prev, n, nums, dp);

         int include = 0;
        if ( prev == -1 || nums[prev] < nums[i] ) {
           
            include = 1 + solve(i+1, i, n, nums, dp);
        }
        return dp[i][prev+1] = max(include, not_include);
    }


    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n+1, -1));

        return solve (0, -1, n, nums, dp);
    }
};
