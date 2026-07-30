class Solution {
public:

    int dia = 0;

    int heightmax(TreeNode* root) {

        if (root == nullptr) return 0;

        int lfth = heightmax(root->left);
        int rgth = heightmax(root->right);

        dia = max(dia, lfth + rgth);

        return 1 + max(lfth, rgth);
    }

    int diameterOfBinaryTree(TreeNode* root) {

        heightmax(root);

        return dia;
    }
};