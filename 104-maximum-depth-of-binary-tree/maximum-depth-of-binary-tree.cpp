/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxDepth(TreeNode* root) {
        
        if(root == NULL) return NULL;
        
        queue<TreeNode*> q;
        q.push(root);

        int depth = 0;

        while(!q.empty()) {
            int size = q.size(); // track the current
            while(size--) {
                TreeNode *curr = q.front();
                q.pop();

                if(curr->left != NULL) {
                    q.push(curr->left);
                }

                if(curr->right != NULL) {
                    q.push(curr->right);
                }
            }
            depth++;
        }

        return depth;


    }
};