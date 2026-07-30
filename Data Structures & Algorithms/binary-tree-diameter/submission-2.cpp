class Solution {
public:

int dia = 0;

    int heightmax( TreeNode* root ) {
        if ( root == nullptr ) return 0;

        int lft = 0;
        lft = 1 + heightmax(root->left);

        int rgt = 0;
        rgt = 1 + heightmax(root->right);

        dia = max( dia, lft+rgt);

        return max(lft, rgt);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        if ( root == nullptr ) return 0;
 
        heightmax(root);

        return dia-2;
    }
};