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

    TreeNode* solve ( TreeNode* curr, TreeNode* p, TreeNode* q ) {
        //TreeNode* ans;

        if ( curr == nullptr ) return nullptr;

        if ( curr->val > max(p->val, q->val) ) 
        return solve(curr->left, p, q);

        if ( curr->val < min(p->val, q->val) )
        return solve(curr->right, p, q);

        return curr;
    }


    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        if ( root == nullptr ) return nullptr;

        return solve(root, p, q);
    }
};
