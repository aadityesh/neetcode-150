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
    void preorder(TreeNode* root, int& cnt, int maxi) {
        if (root == NULL)
            return;
        if (root->val >= maxi)
            cnt++;
        maxi = max(maxi, root->val);
        preorder(root->left, cnt, maxi);
        preorder(root->right, cnt, maxi);
    }
    int goodNodes(TreeNode* root) {
        int cnt = 0;
        int maxi = INT_MIN;
        preorder(root, cnt, maxi);
        return cnt;
    }
};