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
    bool checkSymmetryUsingBFS(TreeNode* root) {

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {

            int size = q.size();
            vector<int> temp = {};

            while (size--) {

                TreeNode* curr = q.front();
                q.pop();

                if(curr->val == 1000) {
                    temp.push_back(curr->val);
                    continue;
                }

                if(curr->left == NULL) {
                    q.push(new TreeNode(1000));
                }

                if (curr->left)
                    q.push(curr->left);
                    
                if(curr->right == NULL) {
                    q.push(new TreeNode(1000));
                }

                if (curr->right)
                    q.push(curr->right);



                temp.push_back(curr->val);
            }

            int n = (temp.size());
            for(int i : temp) {
                cout << i << " ";
            } cout << endl;
            for (int i = 0; i < (n / 2); i++) {
                if (temp[i] != temp[n - i - 1])
                    return false;
            }
        }

        return true;
    }
    bool isSymmetric(TreeNode* root) { return checkSymmetryUsingBFS(root); }
};