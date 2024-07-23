/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    bool path(TreeNode* root, TreeNode* p, vector<TreeNode*>& pathArray) {

        if (root == NULL)
            return false;

        pathArray.push_back(root);

        if (root == p)
            return true;
        if (path(root->left, p, pathArray) || path(root->right, p, pathArray))
            return true;

        pathArray.pop_back();
        return false;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        vector<TreeNode*> path1, path2;
        path(root, p, path1);
        path(root, q, path2);

        TreeNode* result = nullptr;
        for (int i = 0; i < path1.size() && i < path2.size(); i++) {
            if (path1[i] == path2[i]) {
                result = path1[i];
            }
        }

        return result;
    }
};