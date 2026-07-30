class Solution {
public:

    void helper ( vector<int>& nums, vector<int>& ans, int i, vector<vector<int>>& res, int target ) {

        if ( target == 0 ) {
            res.push_back(ans);
            return ;
        }

        if ( target < 0 ) return ;

        if ( i == nums.size() ) return;

        

        //include
        ans.push_back(nums[i]);
        helper(nums, ans, i+1, res, target-nums[i]);

        //backtracking
        ans.pop_back();

        int count = i + 1;
        while ( count < nums.size() && nums[count] == nums[count-1] ) count++;

        //exclude
        helper(nums, ans, count, res, target);

    }


    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {

        sort (nums.begin(), nums.end());

        vector<vector<int>> res;
        vector<int> ans;

        helper(nums, ans, 0, res, target);

        return res;
    }
};
