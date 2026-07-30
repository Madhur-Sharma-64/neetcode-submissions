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
    
     TreeNode* mirror( TreeNode* root ) {
        if ( root == nullptr ) return nullptr;

        TreeNode* lft = root->left;
        TreeNode* rgt = root->right;

        root->right = lft;
        root->left = rgt;

        mirror(root->left);
        mirror(root->right);

        return root;
     }


    TreeNode* invertTree(TreeNode* root) {
        if ( root == nullptr ) return root;

        mirror(root);
        return root;
    }
};
