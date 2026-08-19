class Solution {
public:

    void dfs(int i, int n, int k, vector<int>& ans, vector<vector<int>>& res) {
        if ( ans.size() == k ) {
            res.push_back(ans);
            return;
        }

        if ( i > n ) return;

        ans.push_back(i);
        dfs(i+1, n, k, ans, res);

        ans.pop_back();
        dfs(i+1, n, k, ans, res);

        return;
    }

    vector<vector<int>> combine(int n, int k) {
        vector<int> ans;
        vector<vector<int>> res;

        dfs(1, n, k, ans, res);

        return res;
    }
};