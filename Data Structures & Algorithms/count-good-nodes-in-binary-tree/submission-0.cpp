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

    void solve ( TreeNode* root, int& ans, int max) {
        if ( !root ) return ;

        if ( root->val >= max ) {
            ans++;
            max = root->val;
        }

        solve(root->left, ans, max);
        solve(root->right, ans, max);

        return;
    }


    int goodNodes(TreeNode* root) {
        
        if ( !root ) return 0;

        int ans = 0;

        solve(root, ans, INT_MIN);

        return ans;
        
    }
};
