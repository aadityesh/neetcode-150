class Solution {
public:
    void preorder(TreeNode* root, vector<int>& res) {
        if (root == NULL)
            return;
        res.push_back(root->val);
        preorder(root->left, res);
        preorder(root->right, res);
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {

        if (p == NULL && q == NULL)
            return true;

        if (p == NULL || q == NULL)
            return false;

        if (p->val != q->val)
            return false;

        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {

        // vector<int> subtree;
        // preorder(subRoot, subtree); // 4 1 2

        // // TreeNode* curr = root;
        // vector<int> tree;
        // preorder(root, tree) // 3 4 1 2 5

        // for(int i = 0; i < subtree.size(); i++) {

        //     bool flag = true;
        //     for(int j = 0; j < tree.size(); j++) {

        //         if(subtree[i])

        //     }
        // }

        // if(subRoot == NULL)
        //     return true;
        
        if (root == NULL)
            return false;

        if (isSameTree(root, subRoot))
            return true;

        return (isSubtree(root->left, subRoot) ||
                isSubtree(root->right, subRoot));
    }
};