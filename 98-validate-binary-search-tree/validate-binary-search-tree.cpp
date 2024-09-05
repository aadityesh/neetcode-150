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
    void predecessor(TreeNode* root, long& maxi) {
        if (root == nullptr)
            return;
        maxi = max(maxi, long(root->val));
        predecessor(root->left, maxi);
        predecessor(root->right, maxi);
    }

    void successor(TreeNode* root, long& mini) {
        if (root == nullptr)
            return;
        mini = min(mini, long(root->val));
        successor(root->left, mini);
        successor(root->right, mini);
    }

    bool isValidBST(TreeNode* root) {
        if (root == NULL)
            return true;

        long p = LONG_MIN, s = LONG_MAX;
        predecessor(root->left, p);
        successor(root->right, s);
        cout << p << " " << s << endl;

        if (p >= root->val)
            return false;
        if (s <= root->val)
            return false;

        return isValidBST(root->left) && isValidBST(root->right);
    }
};