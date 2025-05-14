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
    /* int height(TreeNode* root) {

         if (root == NULL)
             return 0;

         int lh = height(root->left);
         int rh = height(root->right);

         return 1 + max(lh, rh);
     }*/

    int optimal(TreeNode* root, bool &res) {

        if (root == NULL)
            return 0;

        int lh = optimal(root->left, res);
        int rh = optimal(root->right, res);

        if (abs(rh - lh) > 1)
            res = false;

        return 1 + max(lh, rh);
    }

    bool isBalanced(TreeNode* root) {

        if (root == NULL)
            return true;

        /*int lh = height(root->left);
        int rh = height(root->right);

        if (abs(rh - lh) > 1)
            return false;
        if (!isBalanced(root->left))
            return false;
        if (!isBalanced(root->right))
            return false;

        return true;*/

        bool result = true;
        optimal(root, result);
        return result;
    }
};