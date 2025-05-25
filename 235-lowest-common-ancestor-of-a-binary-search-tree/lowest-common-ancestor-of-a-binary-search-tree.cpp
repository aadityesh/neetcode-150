/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/*

class Solution {
public:
//p < q;
    TreeNode* lowest(TreeNode* root, TreeNode*p, TreeNode* q) {
        if (p == root || q == root) return root;
        if (root == nullptr) return nullptr;
        if (p->val < root->val && q->val > root->val) {
            return root;
        }

        if (p->val >= root->val && q->val >= root->val) {
            return lowest(root->right, p, q);
        }

        if (p->val <= root->val && q->val <= root->val) {
            return lowest(root->left, p, q);
        }

        return root;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (p->val < q->val) {
            return lowest(root, p, q);
        }
        else return lowest(root, q,p);
    }

    
};

auto init = atexit([]() { ofstream("display_runtime.txt") << "0"; });
*/
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        if(root == NULL) return NULL;

        int curr = root->val;
        if(curr < p->val && curr < q->val) {
            return lowestCommonAncestor(root->right, p, q);
        }

        if (curr > p->val && curr > q->val) {
            return lowestCommonAncestor(root->left, p, q);
        }

        return root;
    }
};