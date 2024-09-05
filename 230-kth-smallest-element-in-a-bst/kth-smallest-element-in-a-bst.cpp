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
    void dfs(TreeNode* root, int& cnt, int k, int& elem) {
        if (root == NULL)
            return;

        dfs(root->left, cnt, k, elem);
        cnt++;
        if (cnt == k) {
            elem = root->val;
            return;
        }
        dfs(root->right, cnt, k, elem);
    }

    int kthSmallest(TreeNode* root, int k) {
        int cnt = 0;
        int elem = -1;
        dfs(root, cnt, k, elem);
        return elem;
    }
};