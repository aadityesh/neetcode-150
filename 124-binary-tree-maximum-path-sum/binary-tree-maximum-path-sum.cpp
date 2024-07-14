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
    int maximumSumPath(TreeNode* root, int& res) {
        if (!root)
            return 0;

        int lh = maximumSumPath(root->left, res);
        int rh = maximumSumPath(root->right, res);

        // Ignoring -ve values
        // inorder to maximize the sum

        lh = (lh >= 0) ? lh : 0;
        rh = (rh >= 0) ? rh : 0;

        // This statement helps us to calculate sum 
        // for the current tree 
        res = max(res, lh + rh + root->val);

        // This statement ensures we choose the
        // the maximum path for the next iteration
        return max(lh, rh) + root->val;
    }

    int maxPathSum(TreeNode* root) {
        if (!root)
            return 0;

        int res = INT_MIN;
        int p = maximumSumPath(root, res);

        return res;
    }
};