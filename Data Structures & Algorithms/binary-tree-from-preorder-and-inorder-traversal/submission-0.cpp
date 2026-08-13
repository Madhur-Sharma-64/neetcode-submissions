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

    int search(vector<int>& inorder, int l, int r, int val) {
        for ( int i = l ; i <= r ; i++ ) {
            if ( inorder[i] == val ) return i;
        }

        return -1;
    }

    TreeNode* bt(vector<int>& preorder, vector<int>& inorder, int& preIdx, int l, int r) {
        if ( l > r ) return nullptr;

        TreeNode* root = new TreeNode(preorder[preIdx]);
        int inIdx = search(inorder, l, r, preorder[preIdx]);
        preIdx++;

        root->left = bt(preorder, inorder, preIdx, l, inIdx-1);
        root->right = bt(preorder, inorder, preIdx, inIdx+1, r);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preIdx = 0;
        return bt(preorder, inorder, preIdx, 0, inorder.size()-1);
    }
};
