/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
int res;

    int dfs(TreeNode* root ) {
        if ( !root ) return 0;

        int l = max(dfs(root->left), 0);
        int r = max(dfs(root->right), 0);

        res = max(root->val + l + r, res);

        return root->val + max(l, r);
        
    }

    int maxPathSum(TreeNode* root) {
        if ( !root ) return 0;

        res = INT_MIN;

        dfs(root);
        return res;
    }
};
