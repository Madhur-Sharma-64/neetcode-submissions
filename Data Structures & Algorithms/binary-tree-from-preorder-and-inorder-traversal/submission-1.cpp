class Solution {
public:

    unordered_map<int, int> mp;

    TreeNode* bt(vector<int>& preorder, vector<int>& inorder,
                 int& preIdx, int l, int r) {

        if (l > r)
            return nullptr;

        int val = preorder[preIdx++];

        TreeNode* root = new TreeNode(val);

        int inIdx = mp[val];

        root->left = bt(preorder, inorder, preIdx,
                        l, inIdx - 1);

        root->right = bt(preorder, inorder, preIdx,
                         inIdx + 1, r);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        for (int i = 0; i < inorder.size(); i++) {
            mp[inorder[i]] = i;
        }

        int preIdx = 0;

        return bt(preorder, inorder, preIdx,
                  0, inorder.size() - 1);
    }
};