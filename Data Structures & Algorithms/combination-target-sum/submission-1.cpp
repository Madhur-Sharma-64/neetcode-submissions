class Solution {
public:
int n;

    void solve ( int i, vector<int>& nums, vector<int>& ans, vector<vector<int>>& res, int target) {
        if ( target == 0 ) {
            res.push_back(ans);
            return;
        }

        if ( i >= n || target < 0 ) return;

        ans.push_back(nums[i]);
        solve(i, nums, ans, res, target-nums[i]);

        ans.pop_back();
        solve(i+1, nums, ans, res, target);

        return;
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        n = nums.size();
        sort(nums.begin(), nums.end());

        vector<vector<int>> res;
        vector<int> ans;

        solve(0, nums, ans, res, target);
        return res;
    }
};
