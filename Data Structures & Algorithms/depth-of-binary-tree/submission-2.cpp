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

    int height ( TreeNode* root ) {
        if ( root == nullptr ) return 0;

        int lft = 0;
        lft = 1 + height(root->left);

        int right = 0 ;
        right = 1 + height(root->right);
        
        return max(lft, right);
    }


    int maxDepth(TreeNode* root) {

        if ( root == nullptr ) return 0;

        return height(root);
        
    }
};
