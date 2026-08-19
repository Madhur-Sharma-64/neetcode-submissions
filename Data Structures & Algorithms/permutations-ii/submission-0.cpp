class Solution {
public:
int n;

    void dfs(vector<int>& nums, vector<int>& ans, vector<vector<int>>& res, vector<bool>& vis) {
        if ( ans.size() == n ) {
            res.push_back(ans);
            return;
        }

        for ( int id = 0 ; id < n ; id++ ) {
            if ( vis[id] ) continue;

            if ( id > 0 && nums[id] == nums[id-1] && !vis[id-1] ) continue;

            vis[id] = true;
            ans.push_back(nums[id]);

            // int skip = id;
            // while ( skip > 0 && skip < n && nums[skip] == nums[skip-1] ) skip++;

            dfs(nums, ans, res, vis);

            vis[id] = false;
            ans.pop_back();
        }

        return;

    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int> ans;
        vector<vector<int>> res;
        n = nums.size();
        vector<bool> vis(n, false);
        sort(nums.begin(), nums.end());

        dfs(nums, ans, res, vis);

        return res;
    }
};