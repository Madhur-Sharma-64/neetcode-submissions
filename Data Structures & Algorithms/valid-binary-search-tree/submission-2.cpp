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

    void dfs( TreeNode* root, vector<int>& tree ) {

        if ( root == nullptr ) return;

        if ( !root->left && !root->right) {
            tree.push_back(root->val);
            return;
        }

        dfs(root->left, tree);
        tree.push_back(root->val);
        dfs(root->right, tree); 
    }

    bool isValidBST(TreeNode* root) {
        if ( root == nullptr ) return true;

        vector<int> tree;
        dfs(root, tree);
        for ( int i = 1 ; i < tree.size() ; i++ ) {
            if ( tree[i] <= tree[i-1] ) return false;
        }

        return true;

    }
};
