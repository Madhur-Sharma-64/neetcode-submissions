class Solution {
public: 

    void helper ( vector<int>& nums, vector<int>& ans, vector<bool>& lolu , vector<vector<int>>& res) {

        int n = nums.size();
    
        if ( ans.size() == nums.size() ) {
            res.push_back(ans);
            return;
        }

        for ( int idx = 0 ; idx < n ; idx++ ) {
            if ( lolu[idx] == true ) continue;

            //choose
            lolu[idx] = true;
            ans.push_back(nums[idx]);
            helper(nums, ans, lolu, res);

            //backtrack
            ans.pop_back();
            lolu[idx] = false;
        }
    }


    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> ans;
        vector<bool> lolu (nums.size(), false);

        helper(nums, ans, lolu, res);
        return res;
    }
};
