class Solution {
public:
    void helper(TreeNode* root, vector<int>& res) {

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
    }

    vector<int> rightSideView(TreeNode* root) {

        if (root == NULL)
            return {};

        vector<int> result;
        helper(root, result);

        return result;
    }
};