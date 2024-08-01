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
    // void inorder(TreeNode* root, vector<int>& res) {
    //     if (root == NULL)
    //         return;
    //     inorder(root->left, res);
    //     res.push_back(root->val);
    //     inorder(root->right, res);
    // }

    bool traversal(TreeNode* root, long mini, long maxi) {

        if(root == NULL) return true;

        if(root->val >= maxi || root->val <= mini) return false;

        return 
        traversal(root->left, mini, root->val) && 
        traversal(root->right, root->val, maxi);


    }

    bool isValidBST(TreeNode* root) {

        // Brute
        /*
        
            vector<int> res;
            inorder(root, res);

            for (int i : res)
                cout << i << " ";

            for (int i = 0; i < res.size() - 1; i++) {
                if (res[i] >= res[i + 1])
                    return false;
            }

            return true;
        */

        // Optimal
        return traversal(root, LONG_MIN, LONG_MAX);
    }
};