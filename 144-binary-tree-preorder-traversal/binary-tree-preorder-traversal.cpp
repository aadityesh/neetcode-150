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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        if (root == NULL)
            return res;

        stack<TreeNode*> st;
        st.push(root);

        while (!st.empty()) {

            // PreOrder -> ROOT L R
            TreeNode* current = st.top();
            st.pop();

            res.push_back(current->val);

            if (current->right)
                st.push(current->right);

            if (current->left)
                st.push(current->left);
        }

        return res;
    }
};