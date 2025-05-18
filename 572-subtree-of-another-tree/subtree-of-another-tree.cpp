
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {

        if (p == NULL && q == NULL)
            return true;
        if (p == NULL && q != NULL)
            return false;
        if (p != NULL && q == NULL)
            return false;
        if (p->val != q->val)
            return false;

        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }

    vector<TreeNode*> BFS(TreeNode* root) {

        if (root == NULL)
            return {};

        queue<TreeNode*> q;
        vector<TreeNode*> vec;
        q.push(root);

        while (!q.empty()) {

            int size = q.size();

            while (size--) {

                TreeNode* curr = q.front();
                q.pop();
                if (curr->left != NULL)
                    q.push(curr->left);
                if (curr->right != NULL)
                    q.push(curr->right);

                vec.push_back(curr);
            }
        }
        return vec;
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {

        vector<TreeNode*> nodes = BFS(root);
        for (auto& node : nodes) {
            if ((node->val == subRoot->val) && isSameTree(node, subRoot))
                return true;
        }
        return false;
    }
};