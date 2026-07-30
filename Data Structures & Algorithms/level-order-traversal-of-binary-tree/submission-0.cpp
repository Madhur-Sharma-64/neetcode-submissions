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

    vector<vector<int>> levelOrder(TreeNode* root) {
        
        vector<vector<int>> res;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {

            vector<int> ans;

            int len = q.size();

            while ( len-- ) {
                TreeNode* node = q.front();
                 q.pop();

                if ( node == nullptr ) continue;

                else {
                    ans.push_back(node->val);
                    q.push(node->left);
                    q.push(node->right);
                }
            }

           

            if ( ! ans.empty() ) res.push_back(ans);
        }

        return res;
    }
};
