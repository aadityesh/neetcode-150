class Solution {
public:
    void helper(TreeNode* root, int level, vector<int>& res) {

        /*
        // Brute
        queue<TreeNode*> q;
        q.push(root);
        vector<vector<int>> traversal;

        while (!q.empty()) {

            int size = q.size();
            vector<int> level;

            for (int i = 0; i < size; i++) {

                TreeNode* front = q.front();
                q.pop();

                if (front->left != NULL)
                    q.push(front->left);
                if (front->right != NULL)
                    q.push(front->right);

                level.push_back(front->val);
            }

            traversal.push_back(level);
        }

        for (vector<int> vec : traversal) {
            res.push_back(vec.back());
        }
        */

        // Optimal
        if (root == NULL)
            return;

        if (level == res.size())
            res.push_back(root->val);

        helper(root->right, level + 1, res);
        helper(root->left, level + 1, res);
    }

    vector<int> rightSideView(TreeNode* root) {

        if (root == NULL)
            return {};

        vector<int> result;
        helper(root, 0, result);

        return result;
    }
};