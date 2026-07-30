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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;

        queue<TreeNode*> q;
        q.push(root);

        while ( !q.empty() ) {
            int len = q.size();

            vector<int> ans;

            while ( len -- ) {
                TreeNode* node = q.front();
                q.pop();

                if ( node == nullptr ) continue;

                ans.push_back(node->val);
                q.push(node->left);
                q.push(node->right);

            }

            if ( ans.size() != 0 ) res.push_back(ans[ans.size()-1]);
        }

        return res;
    }
};
