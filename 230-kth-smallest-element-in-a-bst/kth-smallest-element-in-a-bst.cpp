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
    void pqSetup(TreeNode* root,
                 priority_queue<int, vector<int>, greater<int>>& pq) {

        if (root == NULL)
            return;
        pq.push(root->val);
        pqSetup(root->left, pq);
        pqSetup(root->right, pq);
    }

public:
    int kthSmallest(TreeNode* root, int k) {

        priority_queue<int, vector<int>, greater<int>> pq;
        pqSetup(root, pq);
        while (--k)
            pq.pop();
        return pq.top();
    }
};