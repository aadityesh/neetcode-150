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
    TreeNode* searchBST(TreeNode* root, int target) {

        /*if (root == NULL)
            return NULL;

        if (root->val == target)
            return root;

        if (root->val > target)
            return searchBST(root->left, target);

        return searchBST(root->right, target);*/

        TreeNode* curr = root;
        while (curr) {
            if (curr->val == target)
                return curr;
            else if (curr->val > target)
                curr = curr->left;
            else
                curr = curr->right;
        }

        return NULL;
    }
};