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
private:
    void helper(TreeNode* root, vector<vector<int>>& res) {

        queue<TreeNode*> q;
        q.push(root);
        int index = 1;

        while (!q.empty()) {

            int size = q.size();
            vector<int> level;

            for (int i = 0; i < size; i++) {

                TreeNode* curr = q.front();
                q.pop();

                if (curr->left)
                    q.push(curr->left);
                if (curr->right)
                    q.push(curr->right);

                level.push_back(curr->val);
            }

            if (index % 2 == 0)
                reverse(level.begin(), level.end());

            res.push_back(level);
            index++;
        }
    }

public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {

        if (root == NULL)
            return {};

        vector<vector<int>> res;
        helper(root, res);

        return res;
    }
};