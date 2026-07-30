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

    int ans = 0;

    int height ( TreeNode* root ) {
        if ( root == nullptr ) return 0;

       int lfth = height(root->left);
       int rgth = height(root->right);

        if ( lfth > rgth ) ans = lfth;
        else ans = rgth;

        return 1+ans;
    }


    int maxDepth(TreeNode* root) {

        if ( root == nullptr ) return 0;

        return height(root);
        
    }
};
