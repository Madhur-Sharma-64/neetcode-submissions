class Solution {
public:
int n;

    void solve ( int i, vector<int>& nums, vector<int>& ans, vector<vector<int>>& res) {
        if ( i == n ) {
            res.push_back(ans);
            return;
        }
        if ( i > n ) return;

        ans.push_back(nums[i]);
        solve(i+1, nums, ans, res);

        ans.pop_back();
        solve(i+1, nums, ans, res);

        return;
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        n = nums.size();
        vector<int> ans;
        vector<vector<int>> res;

        solve(0, nums, ans, res);
        return res;
    }
};
