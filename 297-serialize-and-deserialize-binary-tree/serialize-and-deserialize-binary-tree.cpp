/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    void preorder(TreeNode* root, ostringstream& res) {
        if (root == NULL) {
            res << "N"
                << " ";
            return;
        }
        res << root->val << " ";
        preorder(root->left, res);
        preorder(root->right, res);
    }
    string serialize(TreeNode* root) {
        ostringstream tree;
        preorder(root, tree);
        return tree.str();
    }
    TreeNode* buildTree(TreeNode* root, istringstream& data, int& index) {

        string s = "";
        data >> s;

        if (s == "N") {
            return NULL;
        }
        root = new TreeNode(stoi(s));
        root->left = buildTree(root->left, data, index);
        root->right = buildTree(root->right, data, index);
        return root;
    }

    TreeNode* deserialize(string data) {
        TreeNode* root;
        istringstream input(data);
        int index = 0;
        root = buildTree(root, input, index);
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));