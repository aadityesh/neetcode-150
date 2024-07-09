/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {

        if (!root)
            return NULL;

        queue<TreeNode*> q;
        vector<vector<int>> res;
        q.push(root);

        while (!q.empty()) {

            vector<int> level;
            int size = q.size();

            for (int i = 0; i < size; i++) {

                TreeNode* curr = q.front();
                q.pop();

                if (curr->left != NULL)
                    q.push(curr->left);

                if (curr->right != NULL)
                    q.push(curr->right);

                TreeNode* left = curr->left;
                TreeNode* right = curr->right;

                curr->left = right;
                curr->right = left;

                level.push_back(curr->val);
            }

            res.push_back(level);
        }

        // for (int i = 0; i < res.size(); i++) {
        //     reverse(res[i].begin(), res[i].end());
        // }

        // q.push(root);
        // int idx = 0;
        // while (!q.empty()) {

        //     vector<int> level;
        //     int size = q.size();
        //     for (int i = 0; i < size; i++) {
        //         TreeNode* curr = q.front();
        //         curr->val = res[idx][i];
        //         q.pop();

        //         if (curr->left) {
        //             q.push(curr->left);
        //         }

        //         if (curr->right) {
        //             q.push(curr->right);
        //         }

        //         // level.push_back(curr->val);
        //     }
        //     idx++;
        //     // res.push_back(level);
        // }

        return root;
    }
};