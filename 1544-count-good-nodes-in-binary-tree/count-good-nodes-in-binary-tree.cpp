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
    void preorder(TreeNode* root, int maxi, int& cnt) {

        if (root == NULL)
            return;

        if (root->val >= maxi) {
            cnt++;
            maxi = root->val;
        }

        preorder(root->left, maxi, cnt);
        preorder(root->right, maxi, cnt);
    }
    int goodNodes(TreeNode* root) {
        int cnt = 0;
        int maxi = root->val;
        preorder(root, maxi, cnt);
        return cnt;
    }
};