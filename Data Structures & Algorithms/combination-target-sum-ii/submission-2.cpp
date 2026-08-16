class Solution {
public:
int n;

    void helper ( vector<int>& nums, vector<int>& ans, int i, vector<vector<int>>& res, int target ) {

        if ( target == 0 ) {
            res.push_back(ans);
            return ;
        }

        if ( i >= n || target < 0 ) return;

        ans.push_back(nums[i]);
        helper(nums, ans, i+1, res, target-nums[i]);

        ans.pop_back();

        int zeros = i+1;

        while ( zeros < n && nums[zeros] == nums[zeros-1] ) zeros++;
        helper(nums, ans, zeros, res, target);

        return;
    }


    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        n = nums.size();
        sort (nums.begin(), nums.end());

        vector<vector<int>> res;
        vector<int> ans;

        helper(nums, ans, 0, res, target);

        return res;
    }
};
