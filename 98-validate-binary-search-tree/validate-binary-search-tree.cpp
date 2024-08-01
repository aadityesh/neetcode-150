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
    void inorder(TreeNode* root, vector<int>& res) {
        if (root == NULL)
            return;
        inorder(root->left, res);
        res.push_back(root->val);
        inorder(root->right, res);
    }

    bool isValidBST(TreeNode* root) {
        // if (root == NULL)
        //     return false;

        // isValidBST(root->left);
        // isValidBST(root->right);

        // int left = (root->left == NULL) ? INT_MIN : root->left->val;
        // int right = (root->right == NULL) ? INT_MAX : root->right->val;

        // if (left >= root->val || right <= root->val)
        //     return false;

        // return true;
        vector<int> res;
        inorder(root, res);

        for (int i : res)
            cout << i << " ";

        for (int i = 0; i < res.size() - 1; i++) {
            if (res[i] >= res[i + 1])
                return false;
        }

        return true;
    }
};