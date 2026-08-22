class Solution {
public:

    int dfs(TreeNode* root, int can_buy,
             unordered_map<TreeNode*, vector<int>>& dp) {

        if (!root)
            return 0;

        if (dp.count(root) && dp[root][can_buy] != -1)
            return dp[root][can_buy];

        if (!dp.count(root))
            dp[root] = vector<int>(2, -1);

        int ans;

        if (can_buy) {

            int rob =
                root->val
                + dfs(root->left, false, dp)
                + dfs(root->right, false, dp);

            int dontRob =
                dfs(root->left, true, dp)
                + dfs(root->right, true, dp);

            ans = max(rob, dontRob);

        } else {

            ans =
                dfs(root->left, true, dp)
                + dfs(root->right, true, dp);
        }

        return dp[root][can_buy] = ans;
    }

    int rob(TreeNode* root) {

        unordered_map<TreeNode*, vector<int>> dp;

        return dfs(root, true, dp);
    }
};