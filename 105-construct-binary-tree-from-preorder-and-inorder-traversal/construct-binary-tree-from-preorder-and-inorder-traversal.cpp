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
    // Binary Tree - Root , Left, Right
    // preorder - N L R
    // inorder  - L N R

    int linearSearch(vector<int>& in, int key) {
        for (int i = 0; i < in.size(); i++) {
            if (in[i] == key)
                return i;
        }
        return -1;
    }

    TreeNode* helper(vector<int>& pre, vector<int>& in, int &index, int s,
                     int e) {

        // base
        if (index >= pre.size() || s > e)
            return NULL;

        TreeNode* root = new TreeNode(pre[index]);
        int pos = linearSearch(in, pre[index]);
        index++;
        root->left = helper(pre, in, index, s, pos - 1);
        root->right = helper(pre, in, index, pos + 1, e);

        return root;
    }

    TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
        int n = pre.size();
        int index = 0;

        TreeNode* root;
        root = helper(pre, in, index, 0, n - 1);
        return root;
    }
};