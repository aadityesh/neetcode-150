class Codec {
public:
    void dfs(TreeNode* root, ostringstream& out) {

        if (root == NULL) {
            out << "N" << " ";
            return;
        }

        out << root->val << " ";
        dfs(root->left, out);
        dfs(root->right, out);
    }

    TreeNode* buildTree(istringstream& in) {

        string value = "";
        in >> value;

        if (value == "N")
            return NULL;

        int rootData = stoi(value);
        TreeNode* root = new TreeNode(rootData);
        root->left = buildTree(in);
        root->right = buildTree(in);

        return root;
    }

    string serialize(TreeNode* root) {
        ostringstream out;
        dfs(root, out);
        return out.str();
    }

    TreeNode* deserialize(string data) {
        istringstream in(data);
        TreeNode* root = buildTree(in);
        return root;
    }
};
