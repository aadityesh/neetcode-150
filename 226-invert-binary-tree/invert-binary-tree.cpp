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
    TreeNode* invertTree(TreeNode* root) {

        // DFS - Recursive

        /*

        if (root == NULL)
            return NULL;

        TreeNode* curr = root->left;
        root->left = root->right; 
        root->right = curr;

        invertTree(root->left);
        invertTree(root->right);

        return root;

        */

        // DFS - Iterative

        if (root == NULL)
            return NULL;
        
        stack<TreeNode* > st;
        st.push(root);

        while(!st.empty()) {

            TreeNode* curr = st.top();
            st.pop();

            if(curr->left != NULL) {
                st.push(curr->left);
            }

            if(curr->right != NULL) {
                st.push(curr->right);
            }

            swap(curr->left, curr->right);

        }

        return root;
    }
};