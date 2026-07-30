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

    void dfs( TreeNode* root, vector<int>& tree) {
        if ( !root ) return ;
        if ( !root->left && !root->right ) {
            tree.push_back(root->val);
            return;
        }

        dfs(root->left, tree);
        tree.push_back(root->val);
        dfs(root->right, tree);
    }

    int kthSmallest(TreeNode* root, int k) {
        if ( !root ) return -1;

        vector<int> tree;
        dfs(root, tree);
        int n = tree.size();

        if ( k > n ) return -1;

        return tree[k-1];
    }
};
