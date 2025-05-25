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

/*
     void findMaxUsingPreorder(TreeNode* root, long& maxi, long& mini) {
        if (root == NULL)
            return;

        long val = root->val;
        maxi = max(val, maxi);
        mini = min(val, mini);

        findMaxUsingPreorder(root->left, maxi, mini);
        findMaxUsingPreorder(root->right, maxi, mini);
    }

    bool isValidBST(TreeNode* root) {

        if (root == NULL)
            return true;

        long maxi = LONG_MIN;
        long mini = LONG_MAX;
        findMaxUsingPreorder(root->left, maxi, mini);
        long lmax = maxi;

        maxi = LONG_MIN;
        mini = LONG_MAX;
        findMaxUsingPreorder(root->right, maxi, mini);
        long rmax = mini;
        // cout << "L: " << lmax << " Ro: " << root->val << " R: " << rmax <<
        // endl;

        if ((lmax >= root->val || root->val >= rmax))
            return false;

        return isValidBST(root->left) && isValidBST(root->right);
    }
*/

class Solution {
public:
    bool check(TreeNode* root, long& left, long& right) {

        if (root == NULL)
            return true;
        if (left >= root->val || root->val >= right)
            return false;

        long rootValue = root->val;

        return check(root->left, left, rootValue) &&
               check(root->right, rootValue, right);
    }

    bool isValidBST(TreeNode* root) {
        long left = LONG_MIN;
        long right = LONG_MAX;

        return check(root, left, right);
    }
};