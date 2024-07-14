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
    /*
    // Brute
    void preorder(TreeNode* root, vector<int>& res) {

        if (root == NULL) {
            res.push_back(INT_MIN);
            return;
        }

        res.push_back(root->val);
        preorder(root->left, res);
        preorder(root->right, res);
    }

    bool isSameTree(TreeNode* p, TreeNode* q) {

        vector<int> a;
        vector<int> b;

        preorder(p, a);
        preorder(q, b);

        if (a == b)
            return true;

        return false;
    }
    */

    bool isSameTree(TreeNode* p, TreeNode* q) {

        if (p == NULL && q == NULL)
            return true;

        if (p == NULL || q == NULL)
            return false;

        // PreOrder Traversal begins
        // Root L R
        if (p->val != q->val)
            return false;

        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};