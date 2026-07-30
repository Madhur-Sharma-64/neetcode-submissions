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

    TreeNode* mirror(TreeNode* root) {

        if ( root == nullptr ) return nullptr;

        TreeNode* l = root->left;
        TreeNode* r = root->right;

        root->right = l;
        root->left = r;

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
