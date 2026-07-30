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

    int height( TreeNode* root ) {

        if ( root == nullptr ) return 0;

        int lfth = height ( root->left );
        int rgth = height( root-> right);

        return 1 + max(lfth, rgth );
    }


    bool isBalanced(TreeNode* root) {
        if ( root == nullptr ) return true;

        int lh = height(root->left);
        int rh = height(root->right);

        if ( rh - lh > 1 ) return false;
        if ( lh - rh > 1 ) return false;

        return isBalanced(root->left) && isBalanced(root->right);
    }
};
