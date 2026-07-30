class Solution {
public:
    int helper(int i, int currSum, vector<int>& nums, int target,
               vector<vector<int>>& dp, int offset) {

        if (i == nums.size()) {
            return (currSum == target) ? 1 : 0;
        }

        if (dp[i][currSum + offset] != -1)
            return dp[i][currSum + offset];

        int add = helper(i + 1, currSum + nums[i], nums, target, dp, offset);
        int sub = helper(i + 1, currSum - nums[i], nums, target, dp, offset);

        return dp[i][currSum + offset] = add + sub;
    }

    int findTargetSumWays(vector<int>& nums, int target) {

        int sum = 0;
        for (int x : nums)
            sum += x;

        if (abs(target) > sum)
            return 0;

        vector<vector<int>> dp(nums.size(),
                               vector<int>(2 * sum + 1, -1));

        return helper(0, 0, nums, target, dp, sum);
    }
};