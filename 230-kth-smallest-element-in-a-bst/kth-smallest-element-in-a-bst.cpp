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

    void inorder(TreeNode* root, int k, int& cnt, int& ans) {

        if (root == NULL)
            return;

        inorder(root->left, k, cnt, ans);
        
        cnt++;

        if (cnt == k) {
            ans = root->val;
            return;
        }

        inorder(root->right, k, cnt, ans);
    }

public:
    int kthSmallest(TreeNode* root, int k) {

        // Brute
        /*
            priority_queue<int, vector<int>, greater<int>> pq;
            pqSetup(root, pq);
            while (--k)
                pq.pop();
            return pq.top();
        */

        // Optimal
        int ans = -1;
        int cnt = 0;
        inorder(root, k, cnt, ans);
        return ans;
    }
};