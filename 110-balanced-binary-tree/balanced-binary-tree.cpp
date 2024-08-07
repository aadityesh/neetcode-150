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
    // Brute
    /*
    int height(TreeNode* root) {
        if (root == NULL)
            return 0;

        int lh = height(root->left);
        int rh = height(root->right);

        return 1 + max(lh, rh);
    }

    bool isBalanced(TreeNode* root) {

        if (root == NULL)
            return true;

        int x = abs(height(root->left) - height(root->right));

        if (x > 1)
            return false;

        bool left = isBalanced(root->left);
        bool right = isBalanced(root->right);

        if (!left || !right)
            return false;

        return true;
    }
    */

    int height(TreeNode* root) {
        if (root == NULL)
            return 0;

        int lh = height(root->left);
        int rh = height(root->right);

        if (abs(lh - rh) > 1 || lh == -1 || rh == -1)
            return -1;

        return 1 + max(lh, rh);
    }
    bool isBalanced(TreeNode* root) {

        if (height(root) == -1)
            return false;
        return true;
    }
};