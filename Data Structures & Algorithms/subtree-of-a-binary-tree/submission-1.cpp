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

    bool solve ( TreeNode* root, TreeNode* subRoot ) {
        bool yep = false;
        if ( root == nullptr && subRoot == nullptr ) return true;
        if ( root == nullptr && subRoot != nullptr ) return false;
        if ( root != nullptr && subRoot == nullptr ) return false;

        if ( root->val == subRoot->val ) {
            yep = true && solve(root->left, subRoot->left) && solve(root->right, subRoot->right);
        }
        else {
            return false;
        }

        return yep;
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        bool yp = false;
        if (root == nullptr)
        return false;

        if (root->val == subRoot->val && solve(root, subRoot))
        return true;

        return yp = isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
        
    }
};
