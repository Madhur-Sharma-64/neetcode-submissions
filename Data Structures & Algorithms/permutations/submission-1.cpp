class Solution {
public: 
int n;

    void helper (vector<int>& nums, vector<int>& ans, vector<bool>& lolu , vector<vector<int>>& res) {
        if ( ans.size() == n ) {
            res.push_back(ans);
            return;
        }

        //if ( i >= n ) return;

        for ( int cur = 0 ; cur < n ; cur++ ) {
            if ( lolu[cur] ) continue;

            lolu[cur] = true;
            ans.push_back(nums[cur]);
            helper(nums, ans, lolu, res);

            lolu[cur] = false;
            ans.pop_back();
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        n = nums.size();
        vector<vector<int>> res;
        vector<int> ans;
        vector<bool> lolu (nums.size(), false);

        helper(nums, ans, lolu, res);
        return res;
    }
};
